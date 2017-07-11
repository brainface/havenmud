#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("lunge");
  SetRules("at LIV", "");
  SetHelp("Syntax: lunge, lunge at LIV\n\n"
    "You leap forward recklessly and attempt to impale your enemy, "
    "possibly knocking them off their feet.");
  SetStaminaCost(100);
  SetRequiredWeapon("pierce");
  SetRequiredSkills( ([
"pierce combat" : 1,
"swashbuckling" : 1,
    ]) );
}

mixed can_lunge() {
  if (!this_player()->GetInCombat()) { return "lunge who?"; }
  return CanAction(this_player());
}

mixed can_lunge_at_liv() {
  return CanAction(this_player());
}

mixed do_lunge_at_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_lunge() {
  return do_lunge_at_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  object weapon = GetAnyWeapon(who);
  string limb = target->GetRandomLimb("torso");

  if (!weapon) {
    debug("Dude lunged without a weapon. this should not be possible.");
    who->eventPrint("You appear to be mysteriously unarmed!");
    return 0;
  }

  result = GetHit(who,target);

  send_messages( ({ "leap","stab" }),
    "$agent_name $agent_verb forward on one foot and"
    "%^BOLD%^CYAN%^ $agent_verb%^RESET%^ at $target_name!",
    who, target, environment(who));
  if (who->GetTestChar()) debug("lunge result: " + result);
  if (result == -1) {
    send_messages( ({ "tumble","land" }), "$agent_name%^CYAN%^ "
      "$agent_verb%^RESET%^ head over heels past $target_name and "
      "$agent_verb in a heap!",
      who, target, environment(who));
    who->eventCollapse();
    return 1;
  } else if (result == 0) {
    send_messages( ({ "leap" }),
      "$target_name%^CYAN%^ $target_verb%^RESET%^ desperately "
      "away from the blow!",

      who, target, environment(who));
    return 1;
  }

  if (who->GetTestChar()) debug("Lunge should be a success!");

  send_messages( ({"verb"}),
    "$agent_possessive_noun lunge impacts $target_name and sends " 
    "$target_objective %^BOLD%^CYAN%^hurtling%^RESET%^ to the ground!",
    who, target, environment(who) );
  if (who->GetTestChar()) debug("Past funky sendmessage!");

  damage = GetLowDamage(who, weapon);
  if (who->GetTestChar()) debug("lunge damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
  if (who->GetTestChar()) debug("lunge damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
  target->eventCollapse();
  return 1;
}

