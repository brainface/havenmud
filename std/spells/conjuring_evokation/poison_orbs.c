/* Poison Orbs
 * CREATED BY: Ohtar
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpellType(SPELL_COMBAT);
  SetSpell("poison orbs");
  SetDifficulty(90);
  SetSkills( ([
     "conjuring" : 125,
     "evokation" : 125,
    ]) );
  SetEnhanceSkills( ({ "poison magic" }) );
  SetRules("", "LIV");
  SetHelp(
    "This launches multiple orbs of poison from the caster "
    "into the target. It is very powerful and very deadly to "
    "the target.");
}



varargs int eventCast(object who, int level, mixed limb, object array targets) { 
  object victim;
  int num_hits, i;
  string r_limb;
  int damage, d_count;
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
  num_hits = ( (who->GetSkillLevel("conjuring") - 75) /10);
  if (num_hits < 1)  num_hits = 1;
  if (num_hits > 10) num_hits = 10;
  damage   = GetDamage(level);
  foreach(string enhance in GetEnhanceSkills()) {
          int damageboost = who->GetSkillLevel(enhance) / (GetSpellLevel() * 2);
          if (damageboost > 3) damageboost = 3;
          damage += damage * damageboost;
          }
  damage = damage/3;
  if (damage < 5) damage = 5;

  victim = targets[0];

  send_messages( ({ "target", }),
    "$agent_name $agent_verb $target_name with a flurry of poisonous orbs!",
    who, victim, environment(who));
  i = 0;
  while(i < num_hits) {
    r_limb = victim->GetRandomLimb();
    i++;
    if (victim->GetDying()) break;
    if (present(victim, environment(who)) && living(victim)) {
      send_messages("splatter",
         "$agent_possessive_noun orb%^BOLD%^GREEN%^ splatters%^RESET%^ onto $target_possessive_noun " + r_limb + ".",
         who, victim, environment(who));
      d_count += (victim->eventReceiveDamage(who, POISON, damage, 0, r_limb));
      }
  }
  return d_count;
}
