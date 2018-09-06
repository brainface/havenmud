// mahkefel 2017
// acrobatics combat action, area affect, low damage, prevents opponents from
// fighting a round or 10.
// Adds momentum.
#include <lib.h>
#include <damage_types.h>
#include <rounds.h>
#include <vision.h>
#include <conditions.h>
#include <armour_class.h>
inherit LIB_ACTION;

int eventAttack(object who, object* targets);
int eventAction(object who, object* target);

static void create() {
  ::create();
  SetVerb("sweep");
  SetRules("LIV","");
  SetHelp("You sweep back and forth with your quarterstaff, driving your "
  	"opponents back and bruised."
    "\nYou cannot perform acrobatics in heavy armour."  	
  );
  SetStaminaCost(150);
  SetRequiredWeapon("pole");
  SetRequiredSkills( ([
    "acrobatics" : 50,
    "pole combat" : 50,
  ]) );
  SetHands(2);
  SetMaxArmourClass(ARMOUR_REINFORCED);
  SetRage("/verbs/actions/obj/momentum");
}

// overridden for area effect
int eventAction(object who, object* targets) {
  if(who->GetTestChar()) debug ("event action");
  who->SetAttack(targets, (: eventAttack, who, targets :), ROUND_OTHER);
  who->AddStaminaPoints(-StaminaCost);
  return 1;
}

mixed can_sweep() {
  if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
  return CanAction(this_player());
}

mixed can_sweep_liv() {
  return CanAction(this_player());
}

mixed do_sweep_liv(object target) {
  return eventAction(this_player(), ({target}) );
}

mixed do_sweep() {
  return eventAction(this_player(), this_player()->GetEnemies() );
}

int eventAttack(object who, object* targets) {
  int result, damage;
  string limb;
  object weapon = GetAnyWeapon(who);
  
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

  send_messages( ({ "sweep" }),
    "$agent_name%^MAGENTA%^BOLD%^ $agent_verb%^RESET%^ $agent_possessive_noun "
    +weapon->GetKeyName() + "in a wide circle!",
    who, 0, environment(who));

  foreach (object target in targets) {

    result = GetHit(who,target);
    if (who->GetTestChar()) debug("sweep result: " + result);
    //FUMBLE!
    if (result == -1) {
      send_messages( ({ "step" }), "$target_name%^YELLOW%^ "
        "$agent_verb%^RESET%^ backward, easily dodging $agent_possessive_noun "
        "strike!",
        who, target, environment(who));
    // normal miss
    } else if (result == 0) {
      send_messages( ({ "duck" }),
      "$target_name%^YELLOW%^ $agent_verb%^RESET%^ out of the way of "
      "$agent_possessive_noun " + weapon->GetKeyName() + "!",
      who, target, environment(who));
      GetRage()->eventRage(who);
    // hit
    } else {
      if (!weapon) {
        who->eventPrint("You appear to be mysteriously unarmed!");
        return 0;
      }

      limb = target->GetRandomLimb();
      send_messages( ({"knock"}),
        "$agent_name%^BOLD%^%^MAGENTA%^ $agent_verb%^RESET%^ $target_name back!",
        who, target, environment(who) );
      damage = GetLowDamage(who, weapon);
      damage /= 2;
      if (who->GetTestChar()) debug("sweep damage: " + damage);
      damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
      if (who->GetTestChar()) debug("sweep damage after GetDamageInflicted: " + damage);
      target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
      target->AddCondition("Unbalanced!", CONDITION_PREVENT_COMBAT, 1+random(5));
      GetRage()->eventRage(who);
    }
  }
  //
  return 1;
}

