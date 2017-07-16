//
// The 'frostbite' spell
// Created by Thoin@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("ice storm");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([
      "natural magic" : 100,
      "evokation"     : 100,
   ]) );
   SetAutoDamage(0);
   SetDifficulty(150);
   SetDamageType(COLD);
   SetEnhanceSkills( ({ "ice magic" }) );
   SetHelp(
     "This spell unleashes a furious storm of ice and freezing rain "
     "on the target. Like many natural magic spells it can only be "
     "used outside or while under the influence of a natural charge."      
     );
}


int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") || (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
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
  num_hits = (who->GetSkillLevel("natural magic") /10);
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
    "$agent_name $agent_verb a hailstorm of ice and freezing rain on $target_name!",
    who, victim, environment(who));
  i = 0;
  while(i < num_hits) {
    r_limb = victim->GetRandomLimb();
    i++;
if (victim->GetDying()) break;
    if (present(victim, environment(who)) && living(victim)) {
      send_messages("are",
        "$target_name%^BLUE%^ $target_verb%^RESET%^ pelted in the " + r_limb + " by a large chunk of ice.",
         who, victim, environment(who));
      d_count += (victim->eventReceiveDamage(who, COLD, damage, 0, r_limb));
      }
  }
  return d_count;
}
