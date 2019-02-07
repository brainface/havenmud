#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("skewer");
  SetRules("LIV", "");
  SetHelp("You attempt to run your blade directly into the center of an "
    "opponent, generally causing them to regret offending you.");
  SetStaminaCost(320);
  SetRequiredWeapon("pierce");
  SetRequiredSkills( ([
    "pierce combat" : 300,
    "swashbuckling" : 300,
    ]) );
}

mixed can_skewer() {
  if (!this_player()->GetInCombat()) { return "skewer who?"; }
  return CanAction(this_player());
}

mixed can_skewer_liv() {
  return CanAction(this_player());
}

mixed do_skewer_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_skewer() {
  return do_skewer_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  string limb = target->GetRandomLimb();
  object weapon = GetAnyWeapon(who);

  if (!weapon) {
    debug("Dude skewered without a weapon. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unarmed!");
    return 0;
  }

  // prefer torso, if it exists
  if (target->GetLimb("torso")) limb = "torso";

  result = GetHit(who,target);

  send_messages( ({ "hurtle" }),
    "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $agent_reflexive towards $target_name!",
    who, target, environment(who));
  if (result == -1) {
    send_messages( ({ "stumble" }), "$agent_name clumsily%^CYAN%^"
      " $agent_verb%^RESET%^ past $target_name!",
      who, target, environment(who));
    "/verbs/actions/obj/derring"->eventRage(who);
    "/verbs/actions/obj/derring"->eventRage(who);
    return 1;
  }
  if (result = 0) {
    send_messages( ({ "startle" }),
      "$agent_name %^CYAN%^$agent_verb%^RESET%^ $target_name with a "
      "narrow miss!",
      who, target, environment(who));
    "/verbs/actions/obj/derring"->eventRage(who);
    target->AddRecoveryTime(random(50)+1);
    return 1;
  }

  // blow has landed
  send_messages("skewer",
    "$agent_name horrifically%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $target_name with "
    "$agent_possessive "+weapon->GetKeyName() +"!",
    who, target, environment(who) );
  damage = GetHighDamage(who, weapon);
  if (who->GetTestChar()) debug("skewer damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
  if (who->GetTestChar()) debug("skewer damage after GetDamageInflicted: " + damage);
    target->AddBleeding(random(who->GetStatLevel("coordination")/16), who);
  target->AddParalyzed(random(3)+1);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
  if(target && environment(target)) { 
    send_messages( ({"scream"}),
      "$target_name%^BOLD%^GREEN%^ $target_verb%^RESET%^ in surprise an pain!",
      who, target, environment(target));
  }
  return 1;
}

