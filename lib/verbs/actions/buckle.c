#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vision.h>
inherit LIB_ACTION;

int bashUnarmed(object who, object target);

static void create() {
  ::create();
  SetVerb("buckle");
  SetRules("LIV", "");
  SetHelp("Not content to cower behind a gilded shield, a novice "
    "swashbuckler can bash at his opponents weapon, attempting to "
    "shatter it. It is obviously difficult to perform this manuever "
    "without holding a shield in one of your hands.");
  SetStaminaCost(30);
  SetRequiredWeapon("shield"); //shield is not a weapon type. things should be overridden so this doesn't tgo fubar
  SetRequiredSkills( ([
    "swashbuckling" : 1,
  ]) );
}

mixed can_buckle() {
  if (!this_player()->GetInCombat()) { return "buckle who?"; }
  return CanAction(this_player());
}

mixed can_buckle_liv() {
  return CanAction(this_player());
}

mixed do_buckle_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_buckle() {
  return do_buckle_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  int pro, con;
  object weapon, buckler;
  object *pretties;
  string limb = target->GetRandomLimb("torso");

  if (!target) debug("Buckle found no target!");

  if (who->GetProperty("action_debug")) debug("buckling");

  buckler = GetAnyWeapon(who);
  if (!buckler) {
    if (who->GetTestChar()) debug("ain't no shield");
    who->eventPrint("you find yourself mysteriously unshielded!");
    return 1;
  }

  if (target->GetWielded() == ({ }) ) {
    //who->eventPrint(capitalize(target->GetKeyName()) + " has nothing for you to smash!");
    //return 1;
    bashUnarmed(who,target);
    return 1;
  }
  weapon = target->GetWielded()[random(sizeof(target->GetWielded()))];

  pro = who->GetSkillLevel("parry")/2;
  pro += who->GetStatLevel("coordination")/2;
  pro += who->GetLuck();

  con = target->GetSkillLevel("parry");
  con += who->GetStatLevel("agility")/2;
  con += who->GetLuck();

  result = who->eventSkillCheck("swashbuckling", con, pro, 100);

  if (who->GetProperty("action_debug")) debug("thrust sendmessage");
  send_messages( ({ "thrust" }),
    "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $agent_possessive shield at "
      "$target_possessive_noun " +weapon->GetKeyName() + "!",
    who, target, environment(who));

  if (result == -1) {
    if (who->GetProperty("action_debug")) debug("fumble sendmessage");
    send_messages( ({ "sieze","bring" }), "$target_name $target_verb the opportunity, and "
      "$target_verb $target_possessive weapon %^CYAN%^crashing%^RESET%^ down on "
      "$agent_possessive_noun "+buckler->GetKeyName()+".",
      who, target, environment(who));
    buckler->eventDeteriorate(weapon->GetDamageType());
    "/verbs/actions/obj/derring"->eventRage(who);
    "/verbs/actions/obj/derring"->eventRage(who);
    return 1;
  }

  if (result = 0) {
    if (who->GetProperty("action_debug")) debug("miss sendmessage");
    send_messages( ({ "knock" }),
      "$agent_name %^CYAN%^$agent_verb%^RESET%^ $target_possessive_noun "
      + weapon->GetKeyName() + " away harmlessly.",
      who, target, environment(who));
    "/verbs/actions/obj/derring"->eventRage(who);
    return 1;
  }

  if (who->GetProperty("action_debug")) debug("hit sendmessage");
  // blow has landed
  send_messages("",
    "$agent_possessive_noun "+buckler->GetKeyName()+" connects with $target_possessive_noun "
    +weapon->GetKeyName()+" with a loud %^BOLD%^CYAN%^buckle!%^RESET%^",
    who, target, environment(who) );
  weapon->eventDeteriorate(BLUNT);

  // oh hai followup hit
  if( GetHit(who,target) >= 1 ) {
    send_messages("ricochet",
      "$agent_possessive%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $agent_possessive "
      +buckler->GetKeyName()+" off the "+weapon->GetKeyName()+" and into $target_possessive_noun "
      +limb + "!",who,target,environment(who));
    damage = GetLowDamage(who, weapon);
    damage = target->GetDamageInflicted(who,BLUNT,damage,0,limb);
    target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
  }

  return 1;
}


int bashUnarmed(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb("torso");

  if (!weapon) {
    debug("Dude buckled without a shield. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unshielded!");
    return 0;
  }

  result = GetHit(who,target);

  send_messages( ({ "thrust" }),
    "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $agent_possessive shield at "
      "$target_name!",
     who, target, environment(who));

  if (who->GetProperty("action_debug")) debug("buckle result: " + result);
  if (result == -1) {
    send_messages( ({ "catch","fling" }), "$target_name%^CYAN%^ "
      "$target_verb%^RESET%^ $agent_possessive_noun shield arm "
      "and $target_verb $agent_name away!",
      who, target, environment(who));
    who->eventCollapse();
    "/verbs/actions/obj/derring"->eventRage(who);
    "/verbs/actions/obj/derring"->eventRage(who);
    return 1;
  } else if (result == 0) {
    send_messages( ({ "swat" }),
      "$target_name%^CYAN%^ $target_verb%^RESET%^ $agent_possessive_noun "
      + weapon->GetKeyName() + " away!",
      who, target, environment(who));
    "/verbs/actions/obj/derring"->eventRage(who);
    return 1;
  }

  if (who->GetProperty("action_debug")) debug("Lunge should be a success!");

  send_messages( ({"thump"}),
    "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ "
    "$target_name soundly on the " + limb + "!",
    who, target, environment(who) );
  if (who->GetProperty("action_debug")) debug("Past funky sendmessage!");

  damage = GetLowDamage(who, weapon);
  if (who->GetProperty("action_debug")) debug("buckle damage: " + damage);
  damage = target->GetDamageInflicted(who, BLUNT, damage, 0, limb);
  if (who->GetProperty("action_debug")) debug("buckle damage after GetDamageInflicted: " +damage);
  target->eventInflictDamage(who, BLUNT, damage, 0, limb);

  return 1;
}


