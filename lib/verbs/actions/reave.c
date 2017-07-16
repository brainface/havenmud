// Mahkefel 2011
// reave axe combat action
//   hits for low damage and might drop a magical shield
//   can drop lower level shields with higher level
//   applies berserker rage on hit and another tic if a shield drops.

#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("reave");
  SetRules("LIV", "");
  SetHelp("Syntax: reave, reave LIV\n\n"
    "Long a student of unrestrained violence, you have learned "
    "to bring down even metaphysical wards and arcane dweomers "
    "with a focused strike.\n"
    "Reavers are rumored to be especially adept at this attack.");
  SetStaminaCost(250);
  SetRequiredWeapon("hack");
  SetRequiredSkills( ([
    "hack combat" : 200,
    "berserking" : 200,
    ]) );
}

mixed can_reave() {
  if (!this_player()->GetInCombat()) { return "reave who?"; }
  return CanAction(this_player());
}

mixed can_reave_liv() {
  return CanAction(this_player());
}

mixed do_reave_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_reave() {
  return do_reave_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb();
  int minimumWardsToLeave = 4;

  if (!weapon) {
    debug("Dude reaved without a weapon. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unarmed!");
    return 0;
  }

  result = GetHit(who,target);

  send_messages( ({ "stand","stare" }),
    "$agent_name $agent_verb very still for an instant and"
    "%^RED%^ $agent_verb%^RESET%^ at $target_name, as if "
    "trying to focus on something not quite there.",
    who, target, environment(who));
  if (who->GetTestChar()) debug("reave result: " + result);

  if (result == -1) {
    send_messages( ({ "chop" }), "$agent_name%^RED%^ "
      "$agent_verb%^RESET%^ repeatedly at the air beside "
      "$target_name!",
      who, target, environment(who));
    who->eventCollapse();
    return 1;
  } else if (result == 0) {
    send_messages( ({ "scrape" }),
      "$agent_name%^RED%^ $target_verb%^RESET%^ $agent_possessive "
      +weapon->GetKeyName() + " against $target_possessive_noun "
      "side harmlessly.",
      who, target, environment(who));
    return 1;
  }

  if (who->GetTestChar()) debug("reave should be a success!");


  send_messages( ({"slam"}),
    "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ $agent_possessive " +
    weapon->GetKeyName() + " into $target_name at an odd and inefficient angle.",
    who, target, environment(who) );
  if (who->GetTestChar()) debug("Past funky sendmessage!");

  damage = GetLowDamage(who, weapon);
  if (who->GetTestChar()) debug("reave damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
  if (who->GetTestChar()) debug("reave damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

  //"Barbarian rage"
  "/verbs/actions/obj/rage"->eventRage(who);
  // lower level dudes with this verb can only drop the 5th shield.
  // max with an axe can drop every shield
  // this verb will only ever drop 1 shield at a time.
  if(who->GetTestChar()) debug ("calculating reave bullshit");
  // reaver bonus
  if(who->GetClass() == "reaver") {
    minimumWardsToLeave-=1;
  }

  // skill bonus 1
  if(who->GetSkillLevel("berserking") > 400) {
    minimumWardsToLeave--;
  }

  // damn you're a high level axeman bonus
  if(who->GetSkillLevel("berserking") > 600) {
    minimumWardsToLeave--;
  }

  // EPIC
  if(who->GetSkillLevel("berserking") > 800) {
    minimumWardsToLeave--;
  }

  if(who->GetTestChar()) debug ("I should be able to remove 1 shield, leaving a minimum of: "+minimumWardsToLeave);
  if (sizeof(target->GetMagicProtection()) > minimumWardsToLeave) {
    if(who->GetTestChar()) debug ("fuck yaw shield.");
    target->RemoveMagicProtection(1);
    "/verbs/actions/obj/rage"->eventRage(who);
  }

  return 1;
}

