#include <daemons.h>
string GetTown();
string GetCapName();
int eventForce(string);

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

varargs int eventAdvance(object who, string what, string args) {
  string *primes = ({ });
  int x, xpmod;
  int cost, xpcost;
  int *mod;
  string curr = CURRENCY_D->GetTownCurrency(GetTown());
  if (!args) args = what;
  if (args != "level" && !(who->GetSkillClass(args))) {
    eventForce("speak Did you want to <advance level> or <advance SKILL>?");
    return 1; 
  }

  
  if (args == "level") {
      mod   = GetExperienceModifier(who->GetLevel() + 1);
      cost  = mod[0];
      xpmod = mod[1];
      cost  = cost * currency_rate(curr); 
      
      if (who->GetCurrency(curr) < cost) {
        eventForce("speak I charge " + cost + " " + curr + " for that service. Come "
                   "back when you have the money.");
        return 1;
        } 
      if (!sizeof(primes = who->GetPrimarySkills())) {
        eventForce("speak But you don't have any skills!");
        return 1;
        }
      if (who->GetTown() != GetTown() && GetTown() != "Wilderness" && GetTown() != "all") {
        eventForce("speak I only deal with people from " + GetTown() + "!");
        return 1;
        }
      x = who->GetLevel() * 2 * sizeof(primes);
      foreach (string sk in primes) x -= who->GetBaseSkillLevel(sk);
      if (x > 0) {
        eventForce("speak You're not prepared to advance yet!");
        return 1;
      }
      if (who->GetLevel() == 19 && !who->GetApprovedStory() ) {
        who->eventPrint("You need to create a character story first.  <help story>");
        eventForce("sigh");
        return 1;
      }
      if (who->GetLevel() == 8 && !who->GetLongDaemonData(0)[0]) {
        who->eventPrint("You must first <describe> yourself!");
        return 1;
      }
      if (who->GetExperience() < (xpcost = (500 * xpmod) * (who->GetLevel() + 1))) {
        who->eventPrint("You need at least " + xpcost + " experience points to advance your level.");
        eventForce("speak Come back when you're a bit wiser.");
        return 1;
      }
      x = who->GetLevel();     
      who->ResetLevel();
      if (x == who->GetLevel()) {
        eventForce("speak I was unable to advance you.");
        return 1;
      }
      who->eventPrint(GetCapName() + " charges you " + cost + " " + curr + " to advance.");
      who->AddCurrency(curr, -cost);
      who->AddReputation(GetTown(), 2);
      who->AddPartyExperience(-xpcost);
      return 1;
    }
  if (who->GetSkillClass(args)) {
    x   = who->GetBaseSkillLevel(args);
    mod = GetSkillExperienceModifier(x);
    xpmod = mod[1];
    mod = GetSkillExperienceModifier(who->GetLevel());
    cost = mod[0]/20;
    cost  = cost * currency_rate(curr);  
    if (who->GetCurrency(curr) < cost) {
      eventForce("speak I charge " + cost + " " + curr + " for that service. Come "
                 "back when you have the money.");
      return 1;
      }
    if (who->GetTown() != GetTown() && GetTown() != "Wilderness" && GetTown() != "all") {
      eventForce("speak I only deal with people from " + GetTown() + "!");
      return 1;
      }
    if (who->GetExperience() < (xpcost = (50 * (x + 1) * xpmod) * who->GetSkillClass(args))) {
      who->eventPrint("You would need " + xpcost + " experience to advance your " + args + ".");
      eventForce("speak Come back when you've trained some more!");
      return 1;
    }
    if (x >= (who->GetLevel() * 2) + 2) {
      eventForce("speak You need to advance your level before I can advance that skill.");
      return 1;
    }
    who->AddPartyExperience(-(xpcost));
    who->AddSkillLevels(args, 1);
    if (cost) {
    who->AddCurrency(curr, -cost);
    send_messages("charge", "$agent_name $agent_verb $target_name " + cost + " " + curr + " to advance.",
                  this_object(), who, environment() );
    }
    eventForce("speak There you are!  I'm proud to advance you!");
    return 1;
  }
  eventForce("speak But you don't know that skill!");
  return 1;
}
