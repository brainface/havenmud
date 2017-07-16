/* Sword Slinging v 2.0
 * Recoded for Haven 11/08/2007
 * Duuk
 */
#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("slinging");
  SetTrainingPointCost(22);
  SetStaminaCost(4);
  SetSkills( ([
    "slash combat" : 20,
    ]) );
  SetHelp(
    "This is the skill of famed duellers and skilled warriors. "
    "It's use is only for experienced warriors, but it allows "
    "a measure of extra power and attacking speed to one "
    "trained to know the weaknesses of an opponent."
    );
}

int eventSlingSword(object who, int level, object target, object weapon) {
  int pro, con, damage;
  int result;
  string limb = target->GetRandomLimb();
  
  pro = who->GetWeaponChance(target, "slash", 1, sizeof(who->GetWielded()));
  con = target->GetStatLevel("agility")/10;
  con += target->GetLuck();
  con += target->GetDefense();
  
  pro = random(pro);
  con = random(con);
  
  if (con > (pro * 2)) { /* They beat me 2 to 1.  I suck. */
    who->SendCombatMessages(target, -2, weapon, limb);
    return;
    }
  if (!target->eventReceiveAttack(pro, "slash", who, con)) {
    /* Returns a 0 meaning they beat me badly */
    who->SendCombatMessages(target, -1, weapon, limb);
    return;
    }
  
  /* Ok, I hit you.  Now to figure out how hard and dirty, then add some flavor to it. */
  damage = (weapon->eventStrike(target));
  damage = who->GetDamage(damage * 8, "slash combat", target->GetDefense());
  damage = target->eventReceiveDamage(who, weapon->GetDamageType(), damage, 0, limb);
  who->eventTrainCombatStyle("sword slinging", damage);
  who->SendCombatMessages(target, damage, weapon, limb);
  
  return 1;
}
 
int eventStyle(object who, int level, mixed target) {
  int attacks;
  object weapons;
  
  if (arrayp(target)) target = target[0];
  //if (!target) target = who->GetCurrentEnemy();
  if (!sizeof(who->GetWielded())) {
    who->eventPrint("You must be using a slash weapon to use sword slinging.");
    return 1;
  }
  foreach(object weapon in who->GetWielded()) {
    if (weapon->GetWeaponType() != "slash") {
      who->eventPrint(capitalize(weapon->GetShort() + " is not a slash weapon!"));
      return 1;
    }
  }
  weapons = who->GetWielded();
 
  foreach(object weapon in weapons) {
    attacks = (who->GetSkillLevel("slash combat")/50) + 1;
    while(attacks--) 
      eventSlingSword(who, level, target, weapon);
  }
  return 1;
}