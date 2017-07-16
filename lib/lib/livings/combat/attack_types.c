/* combat/attack_types.c
 * controls settings of variation
 * attack strings and damage types
 * Duuktsaryth 3 February 1999
 */
#include <damage_types.h>

string SetMeleeAttackString(string);
int    SetMeleeDamageType(int);
string GetMeleeAttackString();
int    GetMeleeDamageType();
private int    MeleeDamageType;
private string MeleeAttackString;

static void create() {
  MeleeAttackString = "attack";
  MeleeDamageType   = BLUNT;
}

string SetMeleeAttackString(string attack) {
  return (MeleeAttackString = attack);
}

string GetMeleeAttackString() {
  return (MeleeAttackString);
}

int SetMeleeDamageType(int dmg) {
  return (MeleeDamageType = dmg);
}

int GetMeleeDamageType() {
  return (MeleeDamageType);
}

