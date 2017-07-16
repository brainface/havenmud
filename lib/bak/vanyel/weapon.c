/* combat/weapon.c
 * handles all armed combat for the WHOLE WORLD
 * Duuktsaryth 5 February 1999
 */
#include <function.h>
#include <damage_types.h>

int eventWeaponRound(mixed, mixed);
int GetBlind();
int GetWeaponChance(object, string, int, int);
void eventWeaponAttack(object, object, int);

/* virtual lemmings */
int GetTrainingModifier(int);
int GetDamage(int, string, int);
string GetName();
int GetSkillLevel(string);
int GetStatLevel(string);
int eventTrainSkill(string, int, int, int, int);
void SendWeaponMessages(object, int, object, string);
int GetLevel();
int GetLuck();
void eventPrint(string);
int GetCombatStyleLevel(string);

static void create() {
}

int eventWeaponRound(mixed target, mixed args) {
  object *weapons = 0;
  function attack = 0;
  int attacks = 0;
  
  if (arrayp(args)) weapons = args;
  if (functionp(args) && !(functionp(args) & FP_OWNER_DESTED)) 
    attack = args;
  if (!sizeof(weapons) && !functionp(attack)) return 0;
  if (attack) evaluate(attack, target);
    else {
      int num_weapons = sizeof(weapons);
      foreach(object weapon in weapons) {
        if (target->GetDying()) break;
        attacks = 1 + GetSkillLevel(weapon->GetWeaponType() + " attack")/50;
        while (attacks--)
        eventWeaponAttack(target, weapon, num_weapons);
        }
      }
  return target->GetDying();
}

void eventWeaponAttack(object target, object weapon, int attacks) {
  string limb        = target->GetRandomLimb(0);
  string weapon_type = 0;
  int num_hands      = 0;
  int target_level   = target->GetLevel();
  int bonus          = GetTrainingModifier(target_level);
  int power = 0, pro = 0, con = 0;

  if (!weapon) return;
  weapon_type = weapon->GetWeaponType();
  num_hands   = weapon->GetHands();
  if (target->GetDying()) return;
  pro = GetWeaponChance(target, weapon_type, num_hands, attacks);
  con = target->GetStatLevel("agility")/10;
  con += target->GetLuck();
  con += target->GetSkillLevel(weapon_type + " defense");
  if (target->GetCombatStyle() == "parrying") {
    mixed target_weapon = target->GetWielding();
    if (sizeof(target_weapon)) 
      con += (target->GetSkillLevel(target_weapon[0]->GetWeaponType()
              +  " attack")/100 * GetCombatStyleLevel("parrying"));
    }
  
  pro += random(pro);
  con += random(con);

  pro = pro/2;
  con = con/2; // Note: lines added to more appropriately mimic training
             // and damage levels of previous balance, this division should
                  // not actually affect the odds of hitting any.

  if (con > (pro * 2)) { /* They beat me 2 to 1.  I suck. */
//    target->eventTrainSkill(weapon_type + " defense", con, pro, 1,
//            target->GetTrainingModifier(GetLevel()) );
    if (num_hands > 1) eventTrainSkill("multi-hand", pro, con, 0,
                       GetTrainingModifier(target_level) );
    if (attacks > 1) eventTrainSkill("multi-weapon", pro, con, 0,
                       GetTrainingModifier(target_level) );
    eventTrainSkill(weapon_type + " attack", pro, con, 0,
            GetTrainingModifier(target_level) );
    SendWeaponMessages(target, -2, weapon, limb);
    return;
    }
  if (!target->eventReceiveAttack(pro, weapon_type, this_object(), con)) {
    /* Returns a 0 meaning they beat me badly */
//    target->eventTrainSkill(weapon_type + " defense", con, pro, 1,
//            target->GetTrainingModifier(GetLevel()) );
// Lines commented out because eventReceiveAttack trains defense skill
    if (num_hands > 1) eventTrainSkill("multi-hand", pro, con, 0,
                       GetTrainingModifier(target_level) );
    if (attacks > 1) eventTrainSkill("multi-weapon", pro, con, 0,
                       GetTrainingModifier(target_level) );
    eventTrainSkill(weapon_type + " attack", pro, con, 0,
            GetTrainingModifier(target_level) );
    SendWeaponMessages(target, -1, weapon, limb);
    return;
    }
  /* I hit you, but how hard? */
  power = (weapon->eventStrike(target) * pro)/100;
  power = GetDamage(power, weapon_type + " attack", 
                      target->GetSkillLevel(weapon_type + " defense"));
  power = target->eventReceiveDamage(this_object(),
          weapon->GetDamageType(), power, 0, limb);
  weapon->eventReceiveDamage(this_object(), BLUNT, power/20, 0, limb);
  eventTrainSkill(weapon_type + " attack", pro, con, 1,
          GetTrainingModifier(target_level) );
  if (num_hands > 1) eventTrainSkill("multi-hand", pro, con, 1,
                       GetTrainingModifier(target_level) );
  if (attacks > 1) eventTrainSkill("multi-weapon", pro, con, 1,
                       GetTrainingModifier(target_level) );
  if (!target->GetDying()) {
    SendWeaponMessages(target, power, weapon, limb);
    }
    else {
      eventPrint("You slay " + target->GetName() + " without mercy.");
      target->eventPrint(GetName() + " kills you.  You die.");
      environment()->eventPrint(GetName() + " kills " +
                        target->GetName() + ".", ({ this_object(), target }) );
      }
  return;
}

int GetWeaponChance(object target, string type, int hands, int num) {
  int pro = GetSkillLevel(type + " attack");
  int con = 1;

  pro += GetStatLevel("agility")/10;
  if (hands > 1) {
    con += (hands);
    pro += GetSkillLevel("multi-hand");
    }
  if (num > 1) {
    con += (num);
    pro += GetSkillLevel("multi-weapon");
    }
  pro += GetLuck()/10;
  if (GetBlind()) { pro = pro/10; }
  return (pro/con);
  }

