// mahkefel 10 2011
// dirty tricks combat action
//   Essentially a slightly better backstab.
#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("shiv");
  SetRules("LIV");
  SetHelp("You try to slide your blade into an unexpecting mark's "
    "vital organs and swish things around a little. This manuever "
    "may only be attempted outside of combat.");
  SetStaminaCost(50);
  SetRequiredWeapon("knife");
  SetRequiredSkills( ([
    "knife combat" : 1,
    "dirty tricks" : 1,
    "stealth"      : 1,
    ]) );
}

mixed can_shiv_liv() {
  if (this_player()->GetInCombat()) {
    return "You suspect the time for subtlety has passed, as you continue to fight for your life.";
  }
  return CanAction(this_player());
}

mixed do_shiv_liv(object target) {
  return eventAction(this_player(), target);
}

int eventAttack(object who, object target) {
  int result, damage;
  string limb = target->GetRandomLimb();
  object weapon = GetAnyWeapon(who);

  result = GetHit(who,target);

  send_messages( ({ "sidle" }),
    "$agent_name%^BLACK%^BOLD%^ $agent_verb%^RESET%^ "
    "up to $target_name inconspiciously.",
    who, target, environment(who));
  "/verbs/actions/obj/moxie"->eventRage(who);
  if (result == -1) {
    send_messages( ({ "swing" }), "$agent_name%^BOLD%^ $agent_verb"
      "%^RESET%^ wildy at the thin air $target_name occupied moments before!",
      who, target, environment(who));
    who->eventCollapse();
    return 1;
  }
  if (result = 0) {
    send_messages( ({ "flay" }), "$agent_name%^BOLD%^ $agent_verb%^RESET%^ "
      "into $target_possessive_noun " + limb +" with $agent_possessive"+weapon->GetKeyName()+", "
      "causing a bloody but shallow wound!",
      who, target, environment(who));
    target->AddBleeding(random(who->GetStatLevel("coordination")/60)+1);//flavahflave
    target->eventDisplayStatus();
    return 1;
  }

  // blow has landed
  send_messages("stab",
    "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^"
    " $target_possessive_noun " + limb + " deeply with $agent_possessive "
    + weapon->GetKeyName() + "!",
    who, target, environment(who) );

  damage = GetHighDamage(who, weapon);
  if (who->GetTestChar()) debug("Shiv damage: " + damage);
  damage = target->GetDamageInflicted(who, weapon->GetDamageType(),
    damage, 0, limb);
  if (who->GetTestChar())
    debug("Shiv damage after GetDamageInflicted: " + damage);
  target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);

  //BLEEEED for me.
  if (!target->GetBleeding()) {
    target->AddBleeding(random(who->GetStatLevel("coordination")/30)+1);
    target->eventDisplayStatus(); // so they know they're bleeding
  }
  return 1;
}

