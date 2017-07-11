/* Advancement Costs Command
 * Duuk
 * 3/20/2007
 */
#include <lib.h>
#include <daemons.h>
int *GetExperienceModifier(int x) {  
  int cost, xpmod;
  switch(x) {
    case 0..10:
      cost  = 0;
      xpmod = 1;
      break;
    case 11..24:
      cost  = 500;
      xpmod = 2;
      break;
    case 25..49:
      cost  = 2500;
      xpmod = 5;
      break;
    case 50..99:
      cost  = 10000;
      xpmod = 10;
      break;
    case 100..249:
      cost  = 25000;
      xpmod = 25;
      break;
    case 250..299:
      cost  = 100000;
      xpmod = 50;
      break;
    case 300..999:
      cost  = 1000000;
      xpmod = 100;
      break;
    }
  return ({ cost, xpmod });
}

int *GetSkillExperienceModifier(int x) {  
  int cost, xpmod;
  switch(x) {
    case 0..25:
      cost  = 0;
      xpmod = 1;
      break;
    case 26..50:
      cost  = 500;
      xpmod = 2;
      break;
    case 51..100:
      cost  = 2500;
      xpmod = 5;
      break;
    case 101..200:
      cost  = 10000;
      xpmod = 10;
      break;
    case 201..300:
      cost  = 25000;
      xpmod = 25;
      break;
    case 301..399:
      cost  = 100000;
      xpmod = 50;
      break;
    case 400..9999:
      cost  = 1000000;
      xpmod = 100;
      break;
    }
  return ({ cost, xpmod });
}

mixed cmd(string args) {
  int cash_cost;
  string currency;
  string *tmp;
  int xp_cost, i;
  int *mod;
  int xpmod, x;
  string skillcl;
  object target;
  object who = this_player();
  if (creatorp(who) && !args) {
    who->eventPrint("View costs for who?");
    return 1;
  }
  if (!creatorp(this_player())) target = this_player();
    else target = find_living(args);
  if (!target) {
    who->eventPrint("Can't find that person.");
    return 1;
  }
  mod   = GetExperienceModifier(target->GetLevel() + 1);
  cash_cost  = mod[0];
  xpmod = mod[1];
  who->eventPrint("Advancement costs for " + target->GetCapName() + " a level " + target->GetLevel() + " " + target->GetRace());
  cash_cost = cash_cost * currency_rate(currency = CURRENCY_D->GetTownCurrency(target->GetTown())); 
  xp_cost = 500 * xpmod * (target->GetLevel() + 1);
  who->eventPrint("Cost to advance to level " + (target->GetLevel() + 1) + ": " + cash_cost + " " + currency + " and " + xp_cost + " experience");
  i = 1;
  while(i<5) {
    tmp = ({ });
    foreach(string sk in target->GetSkills()) { if (target->GetSkillClass(sk) == i) tmp += ({ sk }); }
    tmp = sort_array(tmp, 1);
    foreach(string skill in tmp) {
      x   = target->GetBaseSkillLevel(skill);
      mod = GetSkillExperienceModifier(x);
      xpmod = mod[1];
      mod = GetSkillExperienceModifier(target->GetLevel());
      cash_cost = mod[0]/20;
      cash_cost = cash_cost * currency_rate(currency = CURRENCY_D->GetTownCurrency(target->GetTown())); 
      xp_cost = 50 * (x + 1) * xpmod * i;
      switch(i) {
        case 1:
          skillcl = "primary  ";
          break;
        case 2:
          skillcl = "secondary";
          break;
        default:
          skillcl = "other    ";
          break;
        }
      who->eventPrint("Advance " + skillcl + " " + sprintf("%-20s", skill) + " to level " + sprintf("%4d", (target->GetSkillLevel(skill) + 1)) + ": " + xp_cost + " XP + " + cash_cost + " " + currency);
    }
    i++;
  }
  return 1;
}
  
string GetHelp(string x) {
  return "Syntax:    costs\n\n\n"
         "Displays XP and Cash costs to advance skills and level.";
}