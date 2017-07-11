/* combat/style.c
 * Controls using alternate attack and defense styles.
 * Duuktsaryth 8 February 1999
 * Outdated as of 18 August 2008
 * Any players with old styles should use the 'refund' command.
 */
#include <daemons.h>
#include <rounds.h>

string SetCombatStyle(string);
string GetCombatStyle();
int eventStyle(object);
int GetCombatStyleLevel(string);
int SetCombatStyleLevel(string, int);
mapping AddCombatStyle(string);
int AddStylePoints(string, int);
varargs int eventTrainCombatStyle(string, int);
string CombatStyle;
mapping CombatStyles;
/* virtuals */
void eventPrint(string);
int SetNextRound(int);
varargs void eventTrainSkill(string, int, int, int);
function SetNextRoundFunction(function);
int AddSkillPoints(string, int);
int AddStaminaPoints(int);
int GetInCombat();

static void create() {
  CombatStyle = 0;
  CombatStyles = ([ ]);
}

/* The checks will be handled in the set verb */


string SetCombatStyle(string style) {
  return (CombatStyle = style);
}

string GetCombatStyle() {
  return (CombatStyle);
}

mapping AddCombatStyle(string style) {
  if (CombatStyles[style]) return (CombatStyles[style]);
  return (CombatStyles[style] = ([ "level" : 1, "points" : 0, ]));
}

int SetCombatStyleLevel(string style, int level) {
  if (!CombatStyles[style]) AddCombatStyle(style);
  return (CombatStyles[style]["level"] = level);
  }

int GetCombatStyleLevel(string style) {
  if (!CombatStyles[style]) return 0;
  return (CombatStyles[style]["level"]);
}

varargs int eventTrainCombatStyle(string style, int amount) {
  object ob = STYLES_D->GetStyle(style);
  if (!ob) return -1;
  return (AddStylePoints(style, amount));
}

void heart_beat() {
  if (GetCombatStyle() && GetInCombat()) {
    object ob = STYLES_D->GetStyle(GetCombatStyle());
    if (!ob) { SetCombatStyle(0); }
    else {
      SetNextRound(ROUND_STYLE);
      SetNextRoundFunction((: eventStyle :));
      }
    AddStaminaPoints(-(ob->GetStaminaCost()));
    }
}

int eventStyle(object target) {
  object who = this_object();
  object style = STYLES_D->GetStyle(GetCombatStyle());

  if (!style) { SetCombatStyle(0); return 0; }
  return style->eventStyle(who, GetCombatStyleLevel(GetCombatStyle()), target);
}


mapping GetCombatStyles() {
  return (CombatStyles);
}

int AddStylePoints(string style, int amount) {
  if (CombatStyles[style]["level"] >= 100) return 100;
  if ((CombatStyles[style]["points"] += amount) >  CombatStyles[style]["level"] * 600) {
      eventPrint("%^YELLOW%^You are more skilled at " + style + ".%^RESET%^");
      CombatStyles[style]["level"]++;
      CombatStyles[style]["points"] = 0;
      }
  return CombatStyles[style]["level"];
}

void Refund() {
  CombatStyles = ([]);
}