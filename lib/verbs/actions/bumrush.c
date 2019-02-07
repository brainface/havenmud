#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("bumrush");
  SetRules("LIV", "");
  SetHelp("You rush towards your target, hoping to overwhelm their attacks "
    "and mortally wound them before they can react.");
  SetStaminaCost(25);
  SetRequiredWeapon("knife");
  SetRequiredSkills( ([
    "knife combat"   : 1,
    "dirty tricks" : 1,
    ]) );
}

mixed can_bumrush() {
  if (!this_player()->GetInCombat()) { return "bumrush who?"; }
  return CanAction(this_player());
}

mixed can_bumrush_liv() {
  return CanAction(this_player());
}

mixed do_bumrush_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_bumrush() {
  return do_bumrush_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage, attacks;
  string limb = target->GetRandomLimb("torso");

  send_messages( ({ "rush" }),
    "$agent_name%^WHITE%^BOLD%^ $agent_verb%^RESET%^ at $target_name, holding out "
    "an arm to block attacks!",
    who, target, environment(who));

  attacks = who->GetSkillLevel("knife combat") / 100 + 1;
  if (who->GetTestChar()) debug("bumrush attacks: " + attacks);

  // much less likely to infinite loop
  foreach( int attack in allocate(attacks) ) {
    if (target->GetDying()) break;
    if (!environment(target)) break;
    if (!environment(who)) break;
    if (environment(who) != environment(target)) break;
    result = GetHit(who,target);
    if (who->GetTestChar()) debug("bumrush result: " + result);
    if (result == -1) {
      send_messages( ({ "grab","struggle" }), "$target_name%^BOLD%^ "
        "$target_verb%^RESET%^ $agent_possessive_noun "
        "knife hand and $target_verb against $agent_possessive attack!",
        who, target, environment(who));
    }
    if (result == 0) {
      send_messages( ({ "turn","stab" }), "$target_name%^BOLD%^ "
        "$target_verb%^RESET%^ aside as $agent_name $agent_verb, avoiding "
        "the full blow of the attack!",
         who, target, environment(who));
    }
    if (result == 1) {
      object weapon = GetAnyWeapon(who);
//      debug("pre weapon check");
      if (!weapon) {
  //      debug("Dude bumrushed without a weapon. this should not be possible.");
        who->eventPrint("You appear to be mysteriously unarmed!");
        return 0;
      }

      // blow has landed
      send_messages("stab",
        "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ deeply into "
        "$target_possessive_noun "+limb+" with $agent_possessive " +
        weapon->GetKeyName()+", causing great pain!",
        who, target, environment(who));
      damage = GetLowDamage(who,weapon);
      if (who->GetTestChar()) debug("bumrush damage: " + damage);
      damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
      if (who->GetTestChar()) debug("bumrush damage after GetDamageInflicted: " + damage);
      target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
      if ( !target->GetBleeding() ) target->AddBleeding(random(10)+1, who);
    }
  }
  return 1;
}

