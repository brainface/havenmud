/* combat/magic.c
 * Supports casting of magic & magic resistance
 * Duuktsaryth 5 February 1999
 */
#include <function.h>
#include <damage_types.h>

int GetMagicResistance();
int eventMagicRound(mixed, function);
/* virtual declarations */
int GetStatLevel(string);
int GetSkillLevel(string);
int GetLevel();
string GetResistance(int);
int GetLuck();
void *AddSave(string *b) { };

mixed MagicBonus;

static void create() {
  AddSave( ({ "MagicBonus" }) );
  
}

mixed SetMagicResistanceBonus(mixed bonus) {
  MagicBonus = bonus;
}

mixed GetMagicResistanceBonus() {
  return MagicBonus;
}

int GetMagicResistance() {
  int val = 0;
  int skill_bonus = 0;
  int magic_bonus = 0;

  val += GetLevel();
  switch (GetResistance(MAGIC)) {
    case "weakness" : val -= 30; break;
    case "low"      : val += 10; break;
    case "medium"   : val += 25; break;
    case "high"     : val += 35; break;
    case "immune"   : val += 75; break;
    }
  foreach(string s in ({ "faith", "conjuring", "natural magic" }) ) {
    if (GetSkillLevel(s) > skill_bonus) skill_bonus = GetSkillLevel(s);
  }
  if (MagicBonus) {
    if (intp(MagicBonus)) magic_bonus = MagicBonus;
    if (functionp(MagicBonus)) magic_bonus = evaluate(MagicBonus);
    }
  return val + GetLuck() + skill_bonus + magic_bonus;
}

int eventMagicRound(mixed target, function spell) {
  evaluate(spell, target);
  return target->GetDying();
}

