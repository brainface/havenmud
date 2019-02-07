// mahkefel 10 2011
#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("gouge");
  SetRules("LIV", "");
  SetHelp("You attempt to gouge your opponent, causing massive annoyance "
    "to their internal organs.");
  SetStaminaCost(220);
  SetRequiredWeapon("knife");
  SetRequiredSkills( ([
    "knife combat" : 200,
    "dirty tricks" : 200,
    ]) );
}

mixed can_gouge() {
  if (!this_player()->GetInCombat()) { return "gouge who?"; }
  return CanAction(this_player());
}

mixed can_gouge_liv() {
  return CanAction(this_player());
}

mixed do_gouge_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_gouge() {
  return do_gouge_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage;
  string limb = target->GetRandomLimb();
  object weapon = GetAnyWeapon(who);

  result = GetHit(who,target);

  send_messages( ({ "dart" }),
    "$agent_name suddenly%^BLACK%^BOLD%^ $agent_verb%^RESET%^ "
    "forward with a menacing sweep at $target_name!",
    who, target, environment(who));
  if (result == -1) {
    send_messages( ({ "stab" }), "$agent_name viciously%^BOLD%^ $agent_verb "
      "%^RESET%^the air beside $target_name!",
      who, target, environment(who));
    return 1;
  }
  if (result = 0) {
    send_messages( ({ "graze" }), "$agent_name%^BOLD%^ $agent_verb%^RESET%^ "
      "$target_possessive_noun cheek with $agent_possessive "+weapon->GetKeyName()+".",
      who, target, environment(who));
    target->AddBleeding(2, who); // flavor
    target->eventDisplayStatus();
    return 1;
  }

  // blow has landed
  send_messages("gouge",
    "$agent_name viciously%^BOLD%^BLACK%^ $agent_verb%^RESET%^"
    " $target_possessive_noun " + limb + " with $agent_possessive "
    + weapon->GetKeyName() + "!",
    who, target, environment(who) );

  damage = GetHighDamage(who, weapon);
  if (who->GetTestChar()) debug("Gouge damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(),
    damage, 0, limb);
  if (who->GetTestChar())
    debug("Gouge damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

  //BLEEEED for me.
  if (!target->GetBleeding()) {
    target->AddBleeding(random(who->GetStatLevel("coordination")/16), who);
    target->eventDisplayStatus(); // so they know they're bleeding
  }
  return 1;
}

