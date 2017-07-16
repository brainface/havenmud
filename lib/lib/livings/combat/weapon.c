/* combat/weapon.c
 * handles all armed combat for the WHOLE WORLD
 * Duuktsaryth 5 February 1999
 */
#include <function.h>
#include <damage_types.h>
#include <vision.h>

int eventWeaponRound(mixed, mixed);
int GetBlind();
int GetEffectiveVision();
int GetWeaponChance(object, string, int, int);
void eventWeaponAttack(object, object, int);

/* virtual lemmings */
int GetTrainingModifier(int);
int GetDamage(int, string, int);
string GetName();
int GetSkillLevel(string);
int GetStatLevel(string);
int eventTrainSkill(string, int, int, int, int);
void SendCombatMessages(object, int, object, string);
int GetLevel();
int GetLuck();
void eventPrint(string);
int GetCombatStyleLevel(string);
int AddExperience(int);
int GetDefense();

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
        attacks = 1 + GetSkillLevel(weapon->GetWeaponType() + " combat")/100;
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
  int bonus          = GetTrainingModifier(target_level/10);
  int power = 0, pro = 0, con = 0;

  if (!weapon) return;
  weapon_type = weapon->GetWeaponType();
  num_hands   = weapon->GetHands();
  if (target->GetDying()) return;
  pro = GetWeaponChance(target, weapon_type, num_hands, attacks);
  con = target->GetStatLevel("agility")/10;
  con += target->GetLuck();
  con += target->GetDefense();


  pro = random(pro);
  con = random(con);

  if (con > (pro * 2)) { /* They beat me 2 to 1.  I suck. */
    SendCombatMessages(target, -2, weapon, limb);
    return;
    }
  if (!target->eventReceiveAttack(pro, weapon_type, this_object(), con)) {
    /* Returns a 0 meaning they beat me badly */
    SendCombatMessages(target, -1, weapon, limb);
    return;
    }
  /* I hit you, but how hard? */
  power = (weapon->eventStrike(target));
  if (weapon->GetProperty("blessed")) power += weapon->GetProperty("blessed");
  power = GetDamage(power *8, weapon_type + " combat", target->GetDefense());
  power = target->GetDamageInflicted(this_object(), weapon->GetDamageType(), power, 0, limb);
  
  SendCombatMessages(target, power, weapon, limb);
  target->eventInflictDamage(this_object(), weapon->GetDamageType(), power, 0, limb);
  weapon->eventReceiveDamage(this_object(), BLUNT, power/20, 0, limb);
  if (target->GetDying()) {
      eventPrint("You slay " + target->GetName() + " without mercy.");
      target->eventPrint(GetName() + " kills you.  You die.");
      environment()->eventPrint(GetName() + " kills " + target->GetName() + ".", ({ this_object(), target }) );
      }
  return;
}

int GetWeaponChance(object target, string type, int hands, int num) {
  int pro = GetSkillLevel(type + " combat");
  int con = 1;

  pro += GetStatLevel("agility")/10;
  pro += GetStatLevel("coordination")/10;
  if (GetSkillLevel("accuracy"))
     pro += (GetSkillLevel("accuracy")/20 || 1);
  if (num > 1) {
    pro += GetSkillLevel("multi-weapon");
    pro = pro * 0.4; /* pro + multi-weapon skill 80% effectiveness */
    }
  pro += GetLuck();
  if (GetBlind()) { pro = pro/10; }
  if (userp()) if (GetEffectiveVision() != VISION_CLEAR) { pro = pro/10; }
  return (pro);
}

