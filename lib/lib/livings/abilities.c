/*    /lib/abilities.c
 *    From the Dead Souls V LPC Library
 *    Handles learned traits
 *    Created by Descartes of Borg 950122
 *    Version: @(#) abilities.c 1.22@(#)
 *    Last modified: 97/01/03
 */
#include <daemons.h>
private int            Level       = 0;
private int            Experience  = 0;
private mapping        Skills      = ([]);
private static mapping SkillsBonus = ([]);

// abstract methods
varargs void eventPrint(string str, mixed args...);
string GetKeyName();
// end abstract methods

string array GetPrimarySkills();
varargs void SetSkill(string skill, int level, int cls);
int GetTestChar();
mixed GetProperty(mixed x);

/* ***************** abilities.c attributes ***************** */
/* GetBaseSkillLevel() returns the unmodified skill level */

int GetLevel() {
    return Level;
}

/* static int ResetLevel()
 *
 * description
 * takes the average skill level of the primary skills and divided by 4
 * and sets the level to that number
 *
 * returns the new level
 */
int ResetLevel() {
    string array skills = GetPrimarySkills();
    int num = sizeof(skills);
    int points = 0;
    int NewLevel = 0;
    
    if( num < 1 ) return (Level = 1);
    foreach(string skill in skills) {
	    points += Skills[skill]["level"];
    }
    NewLevel = ((points/num)/2) + 1;
    if( NewLevel < 1 ) NewLevel = 1;
    if (NewLevel > Level) NewLevel = Level + 1;
    if (NewLevel > 500 && userp()) return Level = 500;
    return Level = NewLevel;
}

int SetLevel(int x) {
    return (Level = x);
}

int GetMaxSkillPoints(string skill, int level) {
  int cl, x;
  
  if( !Skills[skill] ) return 0;
  if( level == 0 ) return 200;
  if( !(cl = Skills[skill]["class"]) ) 
	   Skills[skill]["class"] = 4;
	if (cl < 1 || cl > 4) {
		error(GetKeyName() + " has a fucked up class rank for skill " + skill);
		cl = 4;
		}
	x = level;
	x *= level;
	x *= cl;
	return (x * 400);
}

string array GetPrimarySkills() { 
    return filter(keys(Skills), (: Skills[$1]["class"] == 1 :));
}

/* varargs int AddSkill(string skill, int classes)
 * string skill - the skill being added (required)
 * int classes - the class of the skill (optional)
 *
 * defaults
 * classes defaults to 1, primary class
 *
 * description
 * Used to add a new ability to the list of abilities.  "skill" is the name
 * of the skill being added, and "class" represents the ranking of that skill
 *
 * returns 1 on success, 0 on failure
 */
varargs int AddSkill(string skill, int cls) {
    if( !stringp(skill) ) {
	error("Bad argument 1 to AddSkill().\n\tExpected: string, Got: " +
	      typeof(skill) + "\n");
    }
    if( !nullp(Skills[skill]) ) {
	return 0;
    }
    if( !cls ) {
	cls = 1;
    }
    else if( cls < 0 || cls > 4) {
	return 0;
    }
    Skills[skill] = ([ "level" : 0, "class" : cls ]);
    return 1;
}

mapping GetSkill(string skill) {
    return copy(Skills[skill]);
}

void RemoveSkill(string skill) {
    if( !Skills[skill] ) {
	return;
    }
    map_delete(Skills, skill);
}

/* varargs void SetSkill(string skill, int level, int classes)
 * string skill - the name of the skill being set (required)
 * int level - the level to which that skill is being set (required)
 * int classes - the class to which the skill is being set (optional)
 *
 * defaults
 * classes will default to 1, primary class
 *
 * description
 * sets the skill "skill" to the level "level"
 * if a classes is given, its class is set to it, otherwise the class is
 * set to 1
 * usefule mostly for monster types, probably should have override
 * protections in the user object (should use AddSkill() for users)
 */
varargs void SetSkill(string skill, int level, int cls) {
    if( !stringp(skill) ) {
	error("Bad argument 1 to SetSkill().\n\tExpected: string, Got: " +
	      typeof(skill) + "\n");
    }
    if( !cls ) {
        if( Skills[skill] ) {
	    cls = Skills[skill]["class"];
	}
        else {
	    cls = 1;
	}
    }
    else if( cls < 1 || cls > 4) {
	return 0;
    }
    Skills[skill] = ([ "level" : level, "class" : cls ]);

}

string array GetSkills() {
    return keys(Skills);
}

void AddSkillBonus(string skill, function f) {
    if( !SkillsBonus[skill] ) {
	SkillsBonus[skill] = ([]);
    }
    SkillsBonus[skill][previous_object()] = f;
}

varargs void RemoveSkillBonus(string skill, object ob) {
    if( !SkillsBonus[skill] ) {
	return;
    }
    if( !ob ) {
	ob = previous_object();
    }
    if( !ob || !SkillsBonus[skill][ob] ) {
	return;
    }
    map_delete(SkillsBonus[skill], ob);
}

int GetSkillBonus(string skill) {
    object ob;
    int x = 0;

    if( !SkillsBonus[skill] ) {
	return 0;
    }
    foreach(ob in keys(SkillsBonus[skill])) {
	if( !ob ) continue;
	else x += evaluate(SkillsBonus[skill][ob], skill);
    }
    return x;
}

int GetSkillClass(string skill) { 
    if( !Skills[skill] ) {
	return 0;
    }
    else {
	return Skills[skill]["class"];
    }
}

/* GetSkillLevel() returns the base skill level + any bonuses */


int GetBaseSkillLevel(string skill) { 
  if( !Skills[skill] ) return 0;
	return Skills[skill]["level"];
}

int GetSkillLevel(string skill) { 
    return (GetBaseSkillLevel(skill) + GetSkillBonus(skill));
}

int eventAdvanceSkill(string skill, int new_level) {
  int base;
  if (!Skills[skill]) return 0;
  base = GetBaseSkillLevel(skill);
  Skills[skill]["level"] = new_level;
  eventPrint("%^YELLOW%^Your " + skill + " skill level has advanced to " + new_level + "!%^RESET%^");
  return GetBaseSkillLevel(skill);
}

int AddSkillLevels(string skill, int x) {
  string color = "%^BOLD%^YELLOW%^";
  int y = GetBaseSkillLevel(skill);
  if (x < 0) {
    color = "%^BOLD%^RED%^";
    if (x > y) x = y;
    }
  Skills[skill]["level"] += x;
  if (GetBaseSkillLevel(skill) < 0) SetSkill(skill, 0, GetSkillClass(skill)); 
  eventPrint(color + "Your " + skill + " skill has " + (x > 0 ? "advanced" : "declined") + " to " + GetBaseSkillLevel(skill) + ".%^RESET%^");
  if (x < 0 && userp()) {
    CHAT_D->eventSendChannel("Decline", "players", capitalize(GetKeyName()) + " lost " + x + " levels in " + skill);
  }
  return GetBaseSkillLevel(skill);
}
  

int GetExperience() { return Experience; }
int AddExperience(int x) { 
  // mdw: removing permadeath, zombies gaining no experience is a side effect
  if (this_object()->GetZombie()) {
    eventPrint("You cannot gain experience. Your brain is all wormy!");
    return 0;
  }
  if (x) eventPrint("You receive " + x + " experience.");
  return Experience += x; 
}

varargs int eventCheckSkill(string skill, int con, int bonus, int trainbonus) {
	int level = GetSkillLevel(skill);
	int rnd = random(100) - 50;
	int result = (level + rnd - con + bonus);
	int success;
	int xpgain = 0;
	
	if (result >= 1) { success = 1; } else { success = 0; }
	if (GetTestChar() && GetProperty("skill_debug")) debug("CheckSkill: " + skill + " - con (" + con + ") - bonus (" + bonus + ") - trainbonus (" + trainbonus +")");
	if (GetTestChar() && GetProperty("skill_debug")) debug("CheckSkill Result: " + result);
  xpgain = ( con/2 * (success + 1) + trainbonus + absolute_value(result));
  if (GetTestChar() && GetProperty("skill_debug")) debug("XP Gain: " + xpgain);
  
  AddExperience(con/2 * (success + 1) + trainbonus + absolute_value(result));
	return result;
}


/* ****************** abilities.c driver applies **************** */
static void create() {
}

