/* combat/weapon.c
 * handles all armed combat for the WHOLE WORLD
 * Duuktsaryth 5 February 1999
 */
// mahk 2018:
// moved some numbers around to make offense and defense scale about the same
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
object GetChair();

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
	// mahk 2022: haven's going down, i'm removing combat spam because no one can stop me not even you mel.
        // attacks = 1 + GetSkillLevel(weapon->GetWeaponType() + " combat")/100;
	attacks = 1;
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
  pro = GetWeaponChance(target, weapon_type, num_hands, attacks)+GetLuck();
  // mahk 2018: let's do all this nonsense in one place
  // con = target->GetStatLevel("agility")/10;
  // con += target->GetLuck();
  con = target->GetDefense()+target->GetLuck();


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
  power = (weapon->eventStrike(target)); // event strike is just weapon class
  if (weapon->GetProperty("blessed")) power += weapon->GetProperty("blessed");
  power = GetDamage(power, weapon_type + " combat", target->GetDefense());
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

  // mahk 2018: agility on defense coord on offense
  // pro += GetStatLevel("agility")/10;
  pro += GetStatLevel("coordination")/10;
  //if (GetSkillLevel("accuracy"))
  //   pro += (GetSkillLevel("accuracy")/20 || 1);
  // mahk 2018: adding full accuracy, to scale w/ defense.
  pro += GetSkillLevel("accuracy");
  // taking luck out of here, making wc static
  if (num > 1) {
    pro += GetSkillLevel("multi-weapon");
    pro = pro * 0.4; /* pro + multi-weapon skill 80% effectiveness */
  }

  // mounted combat bonus
  if ( GetChair() && living(GetChair()) ) {
    pro+=GetSkillLevel("riding")/4;
  }
  
  // player offense affected by all poor light levels, npcs affected
  // only by the full blind condition
  if (userp()) if (GetEffectiveVision() != VISION_CLEAR) {
    pro = pro/4;
  } else if (GetBlind()) {
    pro = pro/4;
  }
  return (pro);
}

