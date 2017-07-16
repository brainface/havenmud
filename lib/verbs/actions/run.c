#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("run");
  SetRules("LIV through", "through");
  SetHelp("Syntax: run through, run LIV through\n\n"

    "You attempt to stab your blade clear through someone's "
    "torso in a deadly but reckless attack."

  );
  SetStaminaCost(100);
  SetRequiredWeapon("slash");
  SetRequiredSkills( ([
    "slash combat" : 1,
    "sword slinging" : 1,
    ]) );
}

mixed can_run_through() {
  if (!this_player()->GetInCombat()) { return "run who through?"; }
  return CanAction(this_player());
}

mixed can_run_liv_through() {
  return CanAction(this_player());
}

mixed do_run_liv_through(object target) {
  return eventAction(this_player(), target);
}

mixed do_run_through() {
  return do_run_liv_through(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb("torso");

  if (!weapon) {
    debug("Dude rund without a weapon. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unarmed!");
    return 0;
  }

  result = GetHit(who,target);

  send_messages( ({ "dash" }),
    "$agent_name quickly%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ towards "
    "$target_name, $agent_possessive " +
    weapon->GetKeyName() + " held straight in front of $agent_objective!",
    who, target, environment(who));
  if (who->GetTestChar()) debug("run result: " + result);
  if (result == -1) {
    limb = who->GetRandomLimb();
    send_messages( ({ "mangle","slice" }), "$agent_name%^BOLD%^ "
      "$agent_verb%^RESET%^ the attempt horribly, and "
      "somehow manage to $agent_verb $agent_reflexive in the "+limb+"!",
      who, target, environment(who));

    // hurt self on fumble.
    damage = GetLowDamage(who, weapon);
    if (who->GetTestChar()) debug("oh shit run fumble damage: " + damage);
    damage = who->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
    if (who->GetTestChar()) debug("run damage after GetDamageInflicted: " + damage);
    // cheat to make player not flat out murder themselves.
    if (damage > who->GetHealthPoints() / 4) damage = who->GetHealthPoints() / 4;
    who->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
    return 1;

  } else if (result == 0) {
    send_messages( ({ "lean" }),
      "$target_name%^YELLOW%^ $target_verb%^RESET%^ to the side, narrowly dodging the blade!",
      who, target, environment(who));
    return 1;
  }

  if (who->GetTestChar()) debug("run should be a success!");

  send_messages( ({"run"}),
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ $agent_possessive "+
    weapon->GetKeyName() + " clean through $target_possessive_noun " + limb+"!",
    who, target, environment(who) );
  if (who->GetTestChar()) debug("Past funky sendmessage!");

  damage = GetHighDamage(who, weapon);
  if (who->GetTestChar()) debug("run damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
  if (who->GetTestChar()) debug("run damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

  if(target->GetDying()) {
    "/verbs/actions/obj/bloodlust"->eventRage(who);
  }

  return 1;
}

