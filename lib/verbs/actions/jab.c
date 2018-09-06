#include <lib.h>
#include <damage_types.h>
#include <vision.h>
#include <conditions.h>
#include <armour_class.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("jab");
  SetRules("LIV", "");
  SetHelp("Syntax: jab, jab LIV\n\n"
    "The simplest of pole attacks, you attempt to swiftly stab forward with "
    "your quarterstaff or baton and jab it into something soft of your target. Opponents "
    "generally find it hard to speak after a quarterstaff hits them in the throat."
    "\nYou cannot perform acrobatics in heavy armour."
  );
  SetStaminaCost(50);
  SetRequiredWeapon("pole");
  SetRequiredSkills( ([
    "pole combat" : 1,
    "acrobatics" : 1,
    ]) );
  SetMaxArmourClass(ARMOUR_REINFORCED);
}

mixed can_jab() {
  if (!this_player()->GetInCombat()) { return "jab who?"; }
  return CanAction(this_player());
}

mixed can_jab_liv() {
  return CanAction(this_player());
}

mixed do_jab_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_jab() {
  return do_jab_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb("head");

  if (!weapon) {
    debug("Dude jabbed without a weapon. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unarmed!");
    return 0;
  }

  result = GetHit(who,target);
  // announce attack to room
  send_messages( ({ "jab" }),
    "$agent_name%^BOLD%^MAGENTA%^ $agent_verb%^RESET%^ $agent_possessive " 
    + weapon->GetKeyName() + " at $target_name!",
    who, target, environment(who));
  if (who->GetTestChar()) debug("jab result: " + result);

  // FUMBLEFUMBLE
  // ehhh, lose some combat rounds on a fumble
  if (result == -1) {
  	send_messages( ({ "reel" }), "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ "
      "and struggles to keep $agent_possessive balance as $agent_possessive "
      "strike goes far wide of $target_name!",
    who, target, environment(who) );
    who->AddCondition("Unbalanced!",CONDITION_PREVENT_COMBAT,2);
    "/verbs/actions/obj/momentum"->eventEndRage(who);
    return 1;

  // simple miss block
  } else if (result == 0) {
    send_messages( ({ "" }),
      "$agent_possessive_noun jab%^YELLOW%^ whooshes%^RESET%^ through the air "
      "beside %target_name!",
      who, target, environment(who));
    "/verbs/actions/obj/momentum"->eventRage(who);
    return 1;
  }

  // success block!
  if (who->GetTestChar()) debug("JAB should be a success!");
  
  // make message read neck if it hits the head
  if(limb == "head") limb == "throat";
  send_messages( ({""}),
    "$agent_possessive_noun " + weapon->GetKeyName() + " %^BOLD%^MAGENTA%^"
    "collides%^RESET%^ with $target_possessive_noun " + limb + "!",
    who, target, environment(who) );
  if (who->GetTestChar()) debug("Past funky sendmessage!");
  if (limb == "throat") limb == "head";
  
  // apply damage
  damage = GetLowDamage(who, weapon);
  if (who->GetTestChar()) debug("jab damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
  if (who->GetTestChar()) debug("jab damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
  
  // silence target if they just got hit in the neck
  if(limb == "head") {
    target->AddCondition("Silenced!",CONDITION_PREVENT_TALK, random(10)+2);
  }
  
  "/verbs/actions/obj/momentum"->eventRage(who);
  
  return 1;
}

