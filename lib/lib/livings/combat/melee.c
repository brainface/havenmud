/* combat/melee.c
 * controls non-weapon non-magical combat
 * between livings
 * Duuktsaryth 5 February 1999
 */

#include <rounds.h>
#include <function.h>
#include <vision.h>
#include <damage_types.h>

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
int GetBlessed();


// mahk 2018
string GetClass();
int GetWeaponChance(object, string, int, int);

static void create() {
}


int eventMeleeRound(mixed target, function attack) {
  string *targetlimbs = (target->GetLimbs());
  string targetlimb   = targetlimbs[random(sizeof(targetlimbs))];
  int attacks;

  if (!functionp(attack) || (functionp(attack) & FP_OWNER_DESTED)) {
    // attacks = 1 + (GetSkillLevel("melee combat")/50);
    // mahk 2018: keeping animals dumb.
    // if (GetClass()=="animal") attacks = 1;
    // haha you can't stop me --mahk
    attacks = 2;
    while (attacks--) {
      if (target->GetDying()) break;
      eventMeleeAttack(target, targetlimb);
      }
    }
    else evaluate(attack, target, targetlimb);
  return target->GetDying();
}

// mahk 2018:
// I'm making this MUCH better for players
// at about 500 skil level (player level 250), you have wc 50 fists
// it caps there.
// if the player is blessed, they add damage to their strikes (as if they were weilding)
// and hit with |MAGIC added to their damage (so they can punch wraiths at 1/2 damage)
void eventMeleeAttack(object target, string limb) {
  int pro = 0, con = 0;
  int target_level = target->GetLevel();
  int power = 0;
  int damage = 0;
  int dtype = 0;
  // mahkefel 2017: overriding how it worked before-- npcs were CHAINSAWING
  // a specific limb for like... 24 attacks/round on left foot. but i'm leaving
  // string limb in the function in case other things call it.

  if (target->GetDying()) return;
  limb = target->GetRandomLimb();

  // use the same math as for weapons,
  pro = GetWeaponChance(target, "melee", 1, 1)+GetLuck();
  con = target->GetDefense()+target->GetLuck();

  pro = (random(pro));
  con = (random(con));

  //  debug("modified random pro " + pro + " con " + con);
  if (con > pro * 2) {
  //  debug("Double Con Miss");
    SendCombatMessages(target, -2); /* No target limb, I missed bad. */
    return;
  }
  if (!target->eventReceiveAttack(pro, "melee", this_object(), con)) {
    /* eventReceiveAttack returns 0, meaning they beat my
       skill, ie: target dodged */
    SendCombatMessages(target, -1, 0, limb);
    return;
  }

  dtype = GetMeleeDamageType();
  if (playerp()) {
    // 5 at level 1
    // 10 at level 25
    // 25 at level 100
    // 50 at level 225
    power = 5 + GetSkillLevel("melee combat")/10;
    if (power > 50) power = 50;
    if (GetBlessed()) {
      power += GetBlessed(); // make bless affect melee combat, like it would a weapon.
      dtype = dtype|MAGIC; // you punch magic if blessed, so blessed punchmans can hurt undead, why not?
    }
    // handled in physical.c power *= 8; // weapons *= 8, making them equal here.
  } else { // keeping npcs dumb for now.
    power = GetSkillLevel("melee combat")/25;
  }
  /* Not 0, so I hit the guy. */
  /* Gonna start using 'pro' to reflect damage. Don't mind me. */
  // so this value is melee combat /25, wepaon value is something like weapon class * 8
  // so at level 25, melee has power 2, a stick of wc 12 has power 96. fuck that, jesus.
  damage = GetDamage(power, "melee combat", target->GetDefense());
  damage = target->GetDamageInflicted(this_object(), dtype, damage, 0, limb);

  SendCombatMessages(target, (damage > 0) ? damage : 0, 0, limb);
  target->eventInflictDamage(this_object(), dtype, damage, 0, limb);
  if (target->GetDying()) {
      eventPrint(possessive_noun(target) + " death is now on your head.");
      target->eventPrint(GetName() + " kills you! You die!");
  }
  return;
}

