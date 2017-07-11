/* lib/combatstyle.c
 * template object for combat styles.
 * 8 February 1999
 * Duuktsaryth
 */
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

string Name;
mapping Skills;
int StaminaCost;
int TrainingPointCost;

static void create() {
  daemon::create();
  SetNoClean(1);
  Skills = ([ ]);
  StaminaCost = 0;
  TrainingPointCost = 0;
  }

string SetStyleName(string name) {
  return (Name = name);
  }

string GetStyleName() {
  return (Name);
}
 
mapping SetSkills(mapping m) {
  return (Skills = m);
}

string *GetSkills() {
  return keys(Skills);
}

int SetTrainingPointCost(int x) { return TrainingPointCost = x; }
int SetDevelopmentPointCost(int x) { return TrainingPointCost = x; }

int GetTrainingPointCost() { return TrainingPointCost; }
int GetDevelopmentPointCost() { return TrainingPointCost; }

int GetRequiredSkill(string skill) {
  return (Skills[skill]);
  }

int SetStaminaCost(int cost) {
  return (StaminaCost = cost);
}

int GetStaminaCost() {
  return (StaminaCost);
}

varargs int eventStyle(object who, int level, mixed target) {
  /* This MUST be defined in EVERY style, otherwise it
     will do BadThings[tm]; */
  error("No defined eventStyle in " + base_name(this_object()) +
        ". Please fix this!");
  return -1;
}

int CanStyle(object who) {
  foreach(string skill in GetSkills()) {
    if (!(who->GetSkillLevel(skill) >= GetRequiredSkill(skill))) {
      return 0;
      }
    }
  return 1;
}



string GetHelp(string useless) {
   string Help = help::GetHelp(useless);
  
  Help += "\nRequirements: ";
  if (sizeof(GetSkills()))
  foreach(string skill in GetSkills()) {
     Help += skill + " (" + GetRequiredSkill(skill) + ") ";
   }
  if (!sizeof(GetSkills())) Help += "No required skills.";
  Help += "\nStamina cost per round: " + GetStaminaCost();
  Help += "\nThis style requires " + GetTrainingPointCost() + " development points.";
  return Help;
 }
