/* Chain Lightning v 1.2
 * Recoded from scratch 3 Sept 1997
 * v1.2 coded 3 December 1997
 * Duuktsaryth@Haven
 * Spell causes multiple bolts of energy to hit target.
 * Almost fully recoded March 2005 /Duuk
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpellType(SPELL_COMBAT);
  SetSpell("chain lightning");
  SetDifficulty(40);
  SetSkills( ([
     "conjuring" : 75,
     "evokation" : 75,
    ]) );
  SetEnhanceSkills( ({ "shock magic" }) );
  SetRules("", "LIV");
  SetHelp(
    "This spell sends multiple bolts of energy from the caster "
    "into the target. It is a powerful and deadly spell.");
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
  num_hits = (who->GetSkillLevel("conjuring") /10);
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

  send_messages( ({ "unleash", }),
    "$agent_name $agent_verb a rapid-fire hail of lightning on $target_name!",
    who, victim, environment(who));
  i = 0;
  while(i < num_hits) {
    r_limb = victim->GetRandomLimb();
    i++;
    if (victim->GetDying()) break;
    if (present(victim, environment(who)) && living(victim)) {
      send_messages("sear",
         "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_possessive_noun " +
         r_limb + " with a bolt of energy.",
         who, victim, environment(who));
      d_count += (victim->eventReceiveDamage(who, SHOCK, damage, 0, r_limb));
      }
  }
  return d_count;
}


/* Approved by Duuktsaryth on Wed Sep  3 18:10:05 1997. */
