//
// Syphon Soul
// Thoin@haven
//
#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("syphon soul");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetRecoveryTime(random(5)+2);
  SetDifficulty(175);
  SetSkills( ([
    "necromancy" : 300,
    "faith" : 300,
  ]) );
  SetReligions("Saahagoth");
  SetEnhanceSkills( ({ "fire magic" }) );
  SetHelp(
    "This powerful spell allows an experienced faithful to drain "
    "a target of their life energies and physical energies while "
    "replenishing their own. By harnassing the power of the Black Flame."
  );
}

varargs int eventCast(object who, int level, mixed x, object *t) {
	int damage, damageboost;
  object target = t[0];
  int hpsteal = (level/2 + who->GetSkillLevel("necromancy")/5);
  int pro = who->GetSkillLevel("necromancy") 
    + random(who->GetSkillLevel("necromancy") + level/2);
  int con = (target->GetMagicResistance());
  damage = GetDamage(level);
        damageboost = who->GetSkillLevel("fire magic") / (GetSpellLevel() * 2);
        if (damageboost > 3) damageboost = 3;
        damage += damage * damageboost;

  if( CanAttack(who, target, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        }

  if (hpsteal > 120) {hpsteal = 120;}
    if (pro > con) {
      send_messages(({"capture","send"}),
        "Reaching quickly towards $target_name, "
        "$agent_name $agent_verb $target_objective in a burning grip."
        ,who, target, environment(who) );
      send_messages(({"begin","appear"}),
        "$target_name $target_verb to scream in agony as $agent_possessive "
        "hand shifts, phasing into $target_possessive chest. "
        "%^BOLD%^RED%^Blood%^RESET%^ drips from the gaping wound as "
        "$agent_possessive hand reaches deep into $target_possessive "
        "%^BLUE%^soul%^RESET%^."
        ,who, target, environment(who) );
      target->eventReceiveDamage(who, MAGIC|HEAT, damage, 0);      
      target->AddHealthPoints(-hpsteal);
      target->AddStaminaPoints(-hpsteal);
      who->AddStaminaPoints(hpsteal);
      who->AddHealthPoints(hpsteal);
      return 1;
      }
      else {
      send_messages(({"dodge"}),
        "$target_name $target_verb $agent_possessive_noun grasp."
        ,who, target, environment(who) );        
      return 1;
      }
 }

