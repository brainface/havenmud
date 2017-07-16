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
  object who = this_player();
  x = to_int(args);
  if (!x) return "You're an idiot.";
  if (creatorp(who) && !args) {
    who->eventPrint("View costs for who?");
    return 1;
  }
  mod   = GetExperienceModifier(x + 1);
  cash_cost  = mod[0];
  xpmod = mod[1];
  who->eventPrint("Advancement costs for a level " + x + " generic player");
  cash_cost = cash_cost * currency_rate(currency = "imperials"); 
  xp_cost = 500 * xpmod * (x + 1);
  who->eventPrint("Cost to advance to level " + (x + 1) + ": " + cash_cost + " " + currency + " and " + xp_cost + " experience");
  i = 1;
  while(i<5) {
    tmp = ({ "skill class " + i });
    
    tmp = sort_array(tmp, 1);
    foreach(string skill in tmp) {
      
      mod = GetSkillExperienceModifier((x * 2) + 1);
      xpmod = mod[1];
      mod = GetSkillExperienceModifier(x);
      cash_cost = mod[0]/20;
      cash_cost = cash_cost * currency_rate(currency = "imperials"); 
      xp_cost = 50 * (x + 1) * xpmod * i;
      who->eventPrint("Advance " + sprintf("%-20s", skill) + " to level " + sprintf("%4d", ((x * 2) + 2)) + ": " + xp_cost + " XP + " + cash_cost + " " + currency);
    }
    i++;
  }
  return 1;
}
  
string GetHelp(string x) {
  return "Syntax:    costs X\n\n"
         "Displays XP and Cash costs to advance skills and level for a generic level X player.";
}