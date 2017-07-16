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
  SetVerb("cleave");
  SetRules("LIV","");
  SetHelp("A single soldier or an army, it makes no difference to "
    "you or your axe, as you swing murderously around."
  );
  SetStaminaCost(100);
  SetRequiredWeapon("hack");
  SetRequiredSkills( ([
    "hack combat" : 1,
    "berserking" : 1,
  ]) );

}

// overridden for area effect
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  who->SetAttack(targets, (: eventAttack, who, targets :), ROUND_OTHER);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_cleave() {
  if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed can_cleave_liv() {
  return CanAction(this_player());
}

mixed do_cleave_liv(object target) {
  return eventAction(this_player(), ({target}) );
}

mixed do_cleave() {
  return eventAction(this_player(), this_player()->GetEnemies() );
}


int eventAttack(object who, object* targets) {
  int result, damage;
  string limb;

  // stupid temporary stuff to make one message work right.
  int weapons = sizeof( GetWeapons(who) );
  string word = "axe";

  // try to make sure targets are actually in the room
  if (!targets) return 0;
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

  if (weapons > 1) word = "axes";
  send_messages( ({ "hew" }),
    "$agent_name%^RED%^BOLD%^ $agent_verb%^RESET%^ back and forth with "
    "$agent_possessive " + word + "!",
    who, 0, environment(who));

  foreach (object target in targets) {
    object weapon = GetAnyWeapon(who);
    result = GetHit(who,target);
    if (who->GetTestChar()) debug("cleave result: " + result);
    //FUMBLE!
    if (result == -1) {
      send_messages( ({ "overextend" }), "$agent_name%^RED%^ "
        "$agent_verb%^RESET%^ $agent_reflexive with "
        "$agent_possessive wild blow!",
        who, target, environment(who));
    // normal miss
    } else if (result == 0) {
      send_messages( ({ "whistle" }),
      "$agent_possessive_noun axe%^RED%^ whistles%^RESET%^ as it passes "
      "mere inches from $target_possessive_noun head!",
      who, target, environment(who));
    // hit
    } else {
      if (!weapon) {
        who->eventPrint("You appear to be mysteriously unarmed!");
        return 0;
      }

      limb = target->GetRandomLimb();
      send_messages( ({"cleave"}),
        "$agent_name%^BOLD%^%^RED%^ $agent_verb%^RESET%^ through "
        "$target_possessive_noun " + limb + " with "
        "$agent_possessive " + weapon->GetKeyName() + "!",
        who, target, environment(who) );
      damage = GetLowDamage(who, weapon);
      if (who->GetTestChar()) debug("cleave damage: " + damage);
      damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
      if (who->GetTestChar()) debug("cleave damage after GetDamageInflicted: " + damage);
      target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

      //He like columbus, he get murderous on purpose.
      // does this syntax work?
      "/verbs/actions/obj/rage"->eventRage(who);
    }
  }
  //
  return 1;
}

