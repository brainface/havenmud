/* The ALL NEW Skills Daemon, which will control 
 * skill costs for the new classless system.
 * Much better than letting Imms set the skill
 * costs for themselves, balance wise.
 */
#include <lib.h>
#include <save.h>
#include <daemons.h>
inherit LIB_DAEMON;

mapping Skills, RestrictedSkills;
int GetSkillCost(string skill);
int SetSkillCost(string skill, int cost);
varargs mapping AddSkill(string skill, int cost);
mapping RemoveSkill(string skill);
mapping SetRestrictedSkills(mapping m);
string *AddRestrictedSkills(string, string);
string *GetRestrictedSkills(string);
int CheckRestrictedSkill(string skill, string *skills);

static void create() {
	::create();
	SetNoClean(1);
	if (file_exists(SAVE_SKILLS + ".o")) {
	  unguarded( (: restore_object, SAVE_SKILLS :) );
	}
	unguarded( (: save_object, SAVE_SKILLS :) );
}

int GetSkillCost(string skill) {
	if (Skills[skill])
	  return Skills[skill];
	CHAT_D->eventSendChannel("Error", "error", "Called for skill cost of " + skill + " by "
	                         + identify(previous_object()) + ".");
	return -1;
}

int SetSkillCost(string skill, int cost) {
	if (!Skills[skill]) return -1;
	Skills[skill] = cost;
	unguarded( (: save_object, SAVE_SKILLS :) );
	return cost;
}

varargs mapping AddSkill(string skill, int cost) {
	if (!Skills) Skills = ([]);
	Skills[skill] = cost;
	unguarded( (: save_object, SAVE_SKILLS :) );
	return Skills;
}

mapping RemoveSkill(string skill) {
	map_delete(Skills, skill);
	unguarded( (: save_object, SAVE_SKILLS :) );
	return Skills;
}

mapping GetSkills() {
	return Skills; 
}


mapping SetRestrictedSkills(mapping m) {
  if (!RestrictedSkills) RestrictedSkills = ([]);
  RestrictedSkills = m;
  unguarded( (: save_object, SAVE_SKILLS :) );
  return RestrictedSkills;
}

string *AddRestrictedSkills(string skill1, string skill2) {
  if (!RestrictedSkills) {
    RestrictedSkills = ([]);
    }
  if (!RestrictedSkills[skill1]) {
    RestrictedSkills[skill1] = ({ skill2 });
    } else {
      RestrictedSkills[skill1] += ({ skill2 });
      }
  if (!RestrictedSkills[skill2]) {
    RestrictedSkills[skill2] = ({ skill1 });
    } else {
      RestrictedSkills[skill2] += ({ skill1 });
      }
  unguarded( (: save_object, SAVE_SKILLS :) );
  return RestrictedSkills[skill1];
}

string *GetRestrictedSkills(string skill) {
  if (!RestrictedSkills[skill]) return ({ });
  return RestrictedSkills[skill];
}

int CheckRestrictedSkill(string skill, string *skills) {
  foreach(string sk in skills) {
    if (member_array(sk, GetRestrictedSkills(skill)) != -1) 
      return 1;
    }
  return 0;
}
