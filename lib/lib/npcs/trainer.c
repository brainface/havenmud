/*    /lib/trainer.c
 *    from the Dead Souls  Library
 *    created 960320 by Blitz@Dead Souls
 *    Version: @(#) trainer.c 1.3@(#)
 *    Last modified: 96/10/28
 *    Trainer v2.0 for Space Opera
 *    Saryt
 *    21 November 2001
 */
 
#include <lib.h>
#include <daemons.h>
#include "include/trainer.h"

int eventDropSkill(object who, string verb, string skill);
 
inherit LIB_NPC;
inherit LIB_ADVANCE;
 
private string *TrainingSkills;
private static string LocalCurrency = "imperials";
int RaceRestricted;
string *ranks = ({ "primary", "secondary", "other" });
string GetLocalCurrency();
string SetLocalCurrency(string str);

/**** driver applies ****/
 
static void create() {
    npc::create();
    TrainingSkills = ({});   
    SetNoClean(1);
    SetCommandResponses( ([
      ({ "train", "teach" }) : (: eventTrain :),
      "advance" : (: eventAdvance :),
      "drop"    : (: eventDropSkill :),
      "default" : (: eventHelp :),
    ]) );
    RaceRestricted = 0;
    SetClass("merchant");
/*  Changed the default to no for a short time */
}
 
 
/**** data manipulation ****/
 
string *AddTrainingSkill(string skill) {
    if (!sizeof(TrainingSkills)) TrainingSkills = ({});
    TrainingSkills += ({ skill });
    SetSkill(skill, 1, 1);
    return TrainingSkills;
}
 
string *AddTrainingSkills(string skill) {
  return AddTrainingSkill(skill);
}

string *RemoveTrainingSkill(string skill) {
    TrainingSkills -= ({ skill });
    return TrainingSkills;
}
 
string *SetTrainingSkills(string *mp) { return TrainingSkills = mp; }

string array GetTrainingSkills() { return distinct_array(TrainingSkills); }
 
int SetRaceRestricted(int x) { return RaceRestricted = x; }

int GetRaceRestricted() { return RaceRestricted; }

int GetSkillLevel(string skill) {
	if (member_array(skill, TrainingSkills) != -1) {
		return 4 * GetLevel();
	  }
	return npc::GetSkillLevel(skill);
}


/**** high-level events ****/
 
int eventHelp(object who, string unused) {
    eventForce("speak I am not sure of what you are asking " + (string)who->GetName() + ".");
    eventForce("speak My area of expertise covers " + conjunction(GetTrainingSkills()) + ".");
    eventForce("speak You can \"ask "+GetKeyName()+" to teach <RANK> <SKILL>\" if you have development points, and you will "
               "gain that skill at the rank you choose (primary, secondary, other).");
    return 1;
}
 
int eventTrain(object who, string verb, string skill) {
  int cost;
  int price;
  string rank, action;
  int rnk, crnk;
  if( !who || environment(who) != environment() ) {
	  return 0;
    }
  if (who->GetReputation(GetTown()) < -100) {
    	eventForce("speak Why would I sell to someone as disliked as you?");
    	return 1;
    }
  if (who->GetLevel() == 0) {
    eventForce("speak I can't help you until you've achieved level 1.");
    return 0;
  }
  if (!(who->GetClass())) {
    who->eventPrint("You cannot customize your skills until you have joined a class.");
    return 0;
  }
  if( !sizeof(skill) || !sizeof(verb) ) return eventHelp(who, 0);
  if (sscanf(skill, "%s %s", rank, skill) != 2 || 
    (member_array(rank, ranks) == -1)) {
    	eventForce("speak When you ask me to teach you a new skill, you must "
    	           "specify a rank: primary, secondary, or other. As in ask me "
                 "to teach <RANK> <SKILL>.");
    	return 1;
    }
    if (SKILLS_D->GetSkillCost(skill) == -1) {
    	eventForce("speak Sorry, I know nothing about " + skill + "!");
    	return -1;
    }
    crnk = who->GetSkillClass(skill);
    switch(rank) {
    	case "primary":
    	  cost = SKILLS_D->GetSkillCost(skill) * 3;
    	  rnk = 1;
    	  break;
    	case "secondary":
    	  cost = SKILLS_D->GetSkillCost(skill) * 2;
    	  rnk = 2;
    	  break;
    	case "other":
    	  cost = SKILLS_D->GetSkillCost(skill);
    	  rnk = 4;
    	  break;
    	default:
    	  eventForce("speak You must specify primary, secondary, or other.");
    	  return 1;
    	}
    if (crnk == 4) {
    	cost -= SKILLS_D->GetSkillCost(skill);
      }
    if (crnk == 3) {
    	cost -= SKILLS_D->GetSkillCost(skill);
    	}
    if (crnk == 2) {
    	cost -= SKILLS_D->GetSkillCost(skill) * 2;
    	}
    if (member_array(skill, TrainingSkills) == -1) {
      if (who->GetSkillLevel(skill) == 0) {
    	  eventForce("speak Neither of us know anything about " + skill + ".");
    	  return 1;
      }
      cost *= 3;
      eventForce("speak Since I don't know much about " + skill + " it may be more difficult.");
    }
    if (who->GetDevelopmentPoints() < cost) {
    	eventForce("speak In order for me to teach you " + skill + " as a " + rank + " skill, you need " + cost + " development points.");
    	return 1;
    }
    if (SKILLS_D->CheckRestrictedSkill(skill, who->GetSkills())) {
    	eventForce("speak One of your skills prevents you from learning " + skill);
    	return 1;
    }
    if (GetReligion() != "agnostic") {
    	if (GetReligion() != who->GetReligion()) {
    		eventForce("speak I only teach those of the " + GetReligion() + " faith.");
    		return 1;
    	}
    }
  if (who->GetNationality() != GetTown() && GetTown() != "all") {
  	eventForce("speak Sorry, I only deal with people born in " + GetTown());
  	return 1;
  	}
  if (who->GetSkillClass(skill) && who->GetSkillClass(skill) <= rnk) {
    eventForce("speak Your knowledge of that skill prevents that move!");
    return 1;
    }
   who->AddDevelopmentPoints(-cost);
   who->eventPrint("Adding this skill cost you " + cost + " development points.");
    send_messages("teach",
      "$agent_name $agent_verb $target_name " + skill + ".",
      this_object(), who, environment());
    if (who->GetSkillClass(skill)) action = " moved ";
      else action = " bought ";
    crnk = who->GetSkillLevel(skill);
    if (!crnk) crnk = 1;
    who->SetSkill(skill, crnk, rnk);
    CHAT_D->eventSendChannel(capitalize(GetKeyName()), "reports",  who->GetCapName() + action + skill + " (" + rank + ").");
    return 1;
  }
  

int eventDropSkill(object who, string verb, string skill) {
  int cost;
  string curr;

  if (GetLocalCurrency()) {
	curr = GetLocalCurrency();
	if (CURRENCY_D->GetCurrency(curr) != 1) {
		curr = CURRENCY_D->GetTownCurrency(GetTown());
	}
  } else {
	curr = CURRENCY_D->GetTownCurrency(GetTown());
  }

  switch(who->GetLevel()) {
    case 0..4:
      cost = 500;
      break;
    case 5..24:
      cost = 2000;
      break;
    case 25..49:
      cost = 5000;
      break;
    case 50..99:
      cost = 20000;
      break;
    case 100..249:
      cost = 50000;
      break;
    case 250..300:
      cost = 250000;
      break;
   case 301..999:
      cost = 2500000;
     break;
    }
  cost = cost * currency_rate(curr);
  if (who->GetTown() != GetTown() && GetTown() != "Wilderness" && GetTown() != "all") {
    eventForce("speak I only deal with people from " + GetTown() + "!");
    return 1;
    } 
  if (!skill) {
    eventForce("say What skill would you like to drop?");
    return 1;
  }
  if (!who->GetSkillClass(skill)) {
    eventForce("speak Perhaps you'd like to drop a skill that you have?");
    return 1;
  }
  if (who->GetCurrency(curr) < cost) {
    eventForce("speak I charge " + cost + " " + curr + " for that service.");
    return 1;
  }
  if (who->GetProperty("drop_skill") != skill) {
    eventForce("speak I charge " + cost + " " + curr + " for that service.");
    eventForce("speak Once you drop a skill you will need to repurchase the skill again "
                     "at full price if you ever want it back.  You do NOT receive a refund "
                     "of any development or training that you have put into this skill, it "
                     "is simply lost. If you are sure that you can accept that, please ask "
                     "me again to drop the skill.");
    who->SetProperty("drop_skill", skill);
    return 1;
  }                     
  who->RemoveSkill(skill);
  who->AddCurrency(curr, -cost);
  CHAT_D->eventSendChannel("DROP", "reports", capitalize(who->GetKeyName()) + " dropped " + skill);
  return 1;
}

string GetLocalCurrency() {
    return LocalCurrency;
}

string SetLocalCurrency(string str) {
    return (LocalCurrency = str);
}

void eventGreet(object who) {
  eventForce("speak You can \"ask "+GetKeyName()+" to teach "
               "<RANK> <SKILL>\" if you have development points, and you will "
               "gain that skill at the rank you choose (primary, secondary, other). "
               "You can also <ask " + GetKeyName() + " to drop> a skill.");
}
