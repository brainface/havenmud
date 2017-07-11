#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("harry");
  SetRules("LIV", "");
  SetHelp("You confound your opponent with a rain of blows calculated to confuse rather than maim.");
  SetStaminaCost(120);
  SetRequiredWeapon("pierce");
  SetRequiredSkills( ([
    "pierce combat" : 100,
    "swashbuckling" : 100,
    ]) );
}

mixed can_harry() {
  if (!this_player()->GetInCombat()) { return "harry who?"; }
  return CanAction(this_player());
}

mixed can_harry_liv() {

 return CanAction(this_player());
}

mixed do_harry_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_harry() {
  return do_harry_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int result, damage, disorient, attacks;
  string limb = target->GetRandomLimb();

  send_messages( ({ "circle" }),
    "$agent_name rapidly%^CYAN%^BOLD%^ $agent_verb%^RESET%^ $target_name, striking out with a "
    "series of jabs and feints!",
    who, target, environment(who));

  attacks = who->GetSkillLevel("pierce combat") / 100 +1;
  if (who->GetTestChar()) debug("harry attacks: " + attacks);

  // much less likely to infinite loop
  foreach( int attack in allocate(attacks) ) {
    if (target->GetDying()) break;
    if (!environment(target)) break;
    if (!environment(who)) break;
    if (environment(who) != environment(target)) break;
    result = GetHit(who,target);
    if (who->GetTestChar()) debug("harry result: " + result);
    if (result == -1) {
      send_messages( ({ "fail" }), "$agent_name%^CYAN%^ $agent_verb%^RESET%^ to impress "
        "$target_name with $agent_possessive brilliant manuever.",
        who, target, environment(who));
      "/verbs/actions/obj/derring"->eventRage(who);
      "/verbs/actions/obj/derring"->eventRage(who);
    } else if (result == 0) {
      send_messages( ({ "parry" }), "$agent_name%^CYAN%^ $agent_verb%^RESET%^ "
        "$target_possessive_noun dizzying attack!",
        target, who, environment(who));
      "/verbs/actions/obj/derring"->eventRage(who);
    } else if (result == 1) {
      object weapon = GetAnyWeapon(who);

      if (!weapon) {
        debug("Dude harried without a weapon. this should not be possible.");
        who->eventPrint("You appear to be mysteriously unarmed!");
        return 0;
      }
      // blow has landed
      send_messages("confound",
        "$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $target_name with a "
        "harrying strike of $agent_possessive "+weapon->GetKeyName()+"!",
        who, target, environment(who));
      disorient = (who->GetSkillLevel("swashbuckling") + who->GetSkillLevel("disorient")) / 20;
      damage = GetLowDamage(who,weapon);
      if (who->GetTestChar()) debug("harry damage: " + damage);
      damage = target->GetDamageInflicted(who, weapon->GetDamageType(), damage, 0, limb);
      if (who->GetTestChar()) debug("harry damage after GetDamageInflicted: " + damage);
      target->eventInflictDamage(who, weapon->GetDamageType(), damage, 0, limb);
      target->AddRecoveryTime(random(disorient)+5);
    }
  }
  return 1;
}

