// mahkefel 2011
// swashbuckling combat action, just an area effect. lowish damage,
// highish level.
#include <lib.h>
#include <damage_types.h>
#include <rounds.h>
#include <vision.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("riposte");
  SetRules("LIV","");
  SetHelp("While surrounded, you may attempt to take advantage of your "
    "enemies overconfidence and strike out at all who engage you."
    );
  SetStaminaCost(220);
  SetRequiredWeapon("pierce");
  SetRequiredSkills( ([
    "pierce combat" : 200,
    "swashbuckling" : 200,
  ]) );

}

// overridden for area effect
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  who->SetAttack(targets, (: eventAttack, who, targets :), ROUND_OTHER);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_riposte() {
  debug("can riposte");
  if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed can_riposte_liv() {
  debug ("can riposte liv");
  return CanAction(this_player());
}

mixed do_riposte_liv(object target) {
  debug ("do riposte liv");
  return eventAction(this_player(), ({target}) );
}

mixed do_riposte() {
  debug ("do riposte");
  return eventAction(this_player(), this_player()->GetEnemies() );
}


int eventAttack(object who, object* targets) {
  int result, damage;
  string limb;

  debug("eventAttack");
  // try to make sure targets are actually in the room
  foreach (object target in targets) {
    if (environment(target) != environment(who) ) {
      if(who->GetTestChar()) debug ("enemy not in room");
      targets -= ({target});
    }
    if (member_array(who,target->GetEnemies()) == -1) {
      if(who->GetTestChar()) debug ("target is not an enemey");
      targets -= ({target});
    }
  }
  if (!sizeof(targets)) {
    who->eventPrint("But you fight no one!");
    return 0;
  }
 if(who->GetTestChar()) debug ("invoke message");
  send_messages( ({ "spin", "riposte" }),
    "$agent_name quickly%^CYAN%^BOLD%^ $agent_verb%^RESET%^ about and $agent_verb "
    "$agent_possessive enemies!",
    who, 0, environment(who));

  foreach (object target in targets) {
    object weapon = GetAnyWeapon(who);
    result = GetHit(who,target);
    if (who->GetTestChar()) debug("riposte result: " + result);
    //FUMBLE!
    if (result == -1) {
      send_messages( ({ "fumble" }), "$agent_name%^CYAN%^ "
        "$agent_verb%^RESET%^ $agent_possessive counterattack!",
        who, target, environment(who));
      "/verbs/actions/obj/derring"->eventRage(who);
      "/verbs/actions/obj/derring"->eventRage(who);
    // normal miss
    } else if (result == 0) {
      send_messages( ({ "miss" }),
        "$agent_name%^CYAN%^ $agent_verb%^RESET%^ $target_name with "
        "$agent_possessive clumsy counterattack!",
      who, target, environment(who));
      "/verbs/actions/obj/derring"->eventRage(who);
    // hit
    } else {

      if (!weapon) {
        debug("Dude riposted without a weapon. this should not be possible.");
        who->eventPrint("You appear to be mysteriously unarmed!");
        return 0;
      }

      limb = target->GetRandomLimb();
      send_messages( ({"pierce"}),
        "$agent_name%^BOLD%^%^CYAN%^ $agent_verb%^RESET%^ $target_name with "
        "a deft riposte of $agent_possessive " + weapon->GetKeyName() + "!",
        who, target, environment(who) );
      debug("Past funky sendmessage!");
      damage = GetLowDamage(who, weapon);
      if (who->GetTestChar()) debug("riposte damage: " + damage);
      damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
      if (who->GetTestChar()) debug("riposte damage after GetDamageInflicted: " + damage);
      target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
    }
  }
  //
  return 1;
}

