/*  A disintigration spell
 *  Kind of a nasty high level spell thing
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("disintegrate");
  SetDifficulty(85);
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "evokation" : 100,
     "conjuring" : 100,
      ]) );
  SetHelp(
    "With this spell, a skilled evoker attempts to simply "
    "unmake portions of their enemies body, rendering their "
    "limbs to dust."
  );
}

int eventCast(object who, int level, mixed n, object *targets) {
  object target = targets[0];
  string limb = target->GetRandomLimb("torso");
  int damage = GetDamage(level);
  int limb_hp = target->GetLimb(limb)["health"];
  object severed;
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        }
  if(environment(target) != environment(who)) return 0;
  damage = target->eventReceiveDamage(who, MAGIC, damage, 0, limb);
  if(severed = present(limb, environment(target))) {
     send_messages("disintegrate",
       "$agent_name $agent_verb $target_possessive_noun " + limb + " with $agent_possessive spell!",
        who, target, environment(who) );
     severed->eventDestruct();
     return 1;
  } else {
  send_messages( ({ "attempt", "succeed" }),
    "$agent_name $agent_verb to disintegrate $target_name but $agent_verb "
    "only in doing massive damage to $target_possessive_noun " + limb + ".",
     who, target, environment(who) );
  return 1;
  }
}

