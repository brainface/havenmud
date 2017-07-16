/* combat/melee.c
 * controls non-weapon non-magical combat
 * between livings
 * Duuktsaryth 5 February 1999
 */

#include <rounds.h>
#include <function.h>

int  eventMeleeRound(mixed, function);
int GetBlind();
void eventMeleeAttack(object, string);
/* virtual declarations */
string GetName();
string *GetLimbs();
string GetTorso();
int  GetStatLevel(string);
int  GetSkillLevel(string);
int  GetLevel();
int  GetLuck();
varargs void SendMeleeMessages(object, int, string, string);
int eventTrainSkill(string, int, int, int, int);
void eventPrint(string);
int GetTrainingModifier(int);
int GetDamage(int, string, int);
int GetMeleeDamageType();

static void create() {
}


int eventMeleeRound(mixed target, function attack) {
  string *targetlimbs = (target->GetLimbs());
  string targetlimb   = targetlimbs[random(sizeof(targetlimbs))];
  int attacks;

  if (!functionp(attack) || (functionp(attack) & FP_OWNER_DESTED)) {
    attacks = 1 + (GetSkillLevel("melee attack")/50);
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

  if (target->GetDying()) return;

  pro += GetSkillLevel("melee attack");
  pro += GetStatLevel("agility")/10;
  pro += GetLuck()/10;
  if (GetBlind()) { pro = pro/10; }

  con += target->GetSkillLevel("melee defense");
  con += target->GetStatLevel("agility")/10;
  con += target->GetLuck()/10;

  pro = (pro + random(pro))/2;
  con = (con + random(con))/2;
  if (!limb) {
    SendMeleeMessages(target, -2); /* No target limb, I missed bad. */
    eventTrainSkill("melee attack", pro, con, 0,
                    GetTrainingModifier(target->GetLevel()) );
    target->eventTrainSkill("melee defense", con, pro, 1,
               target->GetTrainingModifier(GetLevel()) );
    return;
    }
  if (!target->eventReceiveAttack(pro, "melee", this_object(), con)) {
    /* eventReceiveAttack returns 0, meaning they beat my
       skill, ie: target dodged */
    SendMeleeMessages(target, -1, limb);
    eventTrainSkill("melee attack", pro, con, 0,
                    GetTrainingModifier(target->GetLevel()) );
    target->eventTrainSkill("melee defense", con, pro, 1,
               target->GetTrainingModifier(GetLevel()) );
    return;
  }
  /* Not 0, so I hit the guy. */                              
  eventTrainSkill("melee attack", pro, con, 1,
                  GetTrainingModifier(target->GetLevel()) );
  target->eventTrainSkill("melee defense", con, pro, 0,
               target->GetTrainingModifier(GetLevel()) );
  /* Gonna start using 'pro' to reflect damage. Don't mind me. */
  pro = GetDamage(0, "melee attack", target->GetSkillLevel("melee defense"));
  pro = target->eventReceiveDamage(this_object(), GetMeleeDamageType(),
                pro, 0, limb);
  if (!target->GetDying()) {
    SendMeleeMessages(target, (pro > 0) ? pro : 0, limb);
    }
    else {
      eventPrint(possessive_noun(target) + " death is now "
                   "on your head.");
      target->eventPrint(GetName() + " kills you! You die!");
            }
  return;
}
