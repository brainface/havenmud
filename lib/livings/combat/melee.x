/* combat/melee.c
 * controls non-weapon non-magical combat
 * between livings
 * Duuktsaryth 5 February 1999
 */

#include <rounds.h>
#include <function.h>
#include <vision.h>

int  eventMeleeRound(mixed, function);
int GetBlind();
int GetEffectiveVision();
void eventMeleeAttack(object, string);
/* virtual declarations */
string GetName();
string *GetLimbs();
string GetTorso();
int  GetStatLevel(string);
int  GetSkillLevel(string);
int  GetLevel();
int  GetLuck();
varargs void SendCombatMessages(object, int, object, string);
int eventTrainSkill(string, int, int, int, int);
void eventPrint(string);
int GetTrainingModifier(int);
int GetDamage(int, string, int);
int GetMeleeDamageType();
int AddExperience(int x);
int GetCombatStyleLevel(string);
int GetDefense();

static void create() {
}


int eventMeleeRound(mixed target, function attack) {
  string *targetlimbs = (target->GetLimbs());
  string targetlimb   = targetlimbs[random(sizeof(targetlimbs))];
  int attacks;

  if (!functionp(attack) || (functionp(attack) & FP_OWNER_DESTED)) {
    attacks = 1 + (GetSkillLevel("melee combat")/50);
    while (attacks--) {
      if (target->GetDying()) break;
      eventMeleeAttack(target, targetlimb);
      }
    }
    else evaluate(attack, target, targetlimb);
  return target->GetDying();
}

void eventMeleeAttack(object target, string limb) {
  int pro = 0, con = 0;
  int target_level = target->GetLevel();

  if (target->GetDying()) return;

  pro += GetSkillLevel("melee combat");
  pro += GetStatLevel("agility")/10;
  pro += GetLuck()/10;
  if (GetSkillLevel("accuracy"))
     pro += (GetSkillLevel("accuracy")/20 || 1);
  if (GetBlind()) { pro = pro/10; }
  if (userp())if (GetEffectiveVision() != VISION_CLEAR) { pro = pro/10; }
  con += target->GetDefense();
  con += target->GetStatLevel("agility")/10;
  con += target->GetLuck()/10;


//  debug("pro " + pro + " con " + con);
  pro = (random(pro));
  con = (random(con));
//  debug("modified random pro " + pro + " con " + con);
  if (con > pro * 2) {
//    debug("Double Con Miss");
    SendCombatMessages(target, -2); /* No target limb, I missed bad. */
    return;
    }
  if (!target->eventReceiveAttack(pro, "melee", this_object(), con)) {
    /* eventReceiveAttack returns 0, meaning they beat my
       skill, ie: target dodged */
    SendCombatMessages(target, -1, 0, limb);
    return;
  }
  /* Not 0, so I hit the guy. */                              
  /* Gonna start using 'pro' to reflect damage. Don't mind me. */
  pro = GetDamage(GetSkillLevel("melee combat")/25, "melee combat", target->GetDefense());
  pro = target->GetDamageInflicted(this_object(), GetMeleeDamageType(), pro, 0, limb);
  
  SendCombatMessages(target, (pro > 0) ? pro : 0, 0, limb);
  target->eventInflictDamage(this_object(), GetMeleeDamageType(), pro, 0, limb);
  if (target->GetDying()) {
      eventPrint(possessive_noun(target) + " death is now on your head.");
      target->eventPrint(GetName() + " kills you! You die!");
  }
  return;
}
