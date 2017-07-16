#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

void InputSkillName(string skill);
void InputSkillCost(string skill, string cost);
void RemoveSkill(string skill);
void ChangeSkillName(string skill);
void ChangeSkillCost(string skill, string cost);

mixed cmd(string args) {
        mapping skills;
        string *tmp = ({});
        string *sorted;
                if (sagep(this_player()) && args) {
                  if (args == "add") {
                        this_player()->eventPrint("Enter the name of the skill to add: ");
                        input_to( (: InputSkillName :) );
                        return 1;
                        }
                  if (args == "remove") {
                        this_player()->eventPrint("Enter the skill to remove: ");
                        input_to( (: RemoveSkill :) );
                        return 1;
                  }
                  if (args == "change") {
                        this_player()->eventPrint("Enter the skill that you wish to modify: ");
                        input_to( (: ChangeSkillName :) );
                        return 1;
                  }
          }     
        skills = SKILLS_D->GetSkills();
        sorted = sort_array(keys(skills), 1);
        tmp += ({ "%^BOLD%^BLUE%^Skills List as of " + ctime(time()) + "%^RESET%^\n" });
        tmp += ({ sprintf("%-20s %|20s %|20s %|20s",
			              "Skill Name",
						  "Primary Cost",
						  "Secondary Cost",
						  "Other Cost" ) });
        foreach(string skill in sorted) {
                tmp += ({ sprintf("%-20s %|20i %|20i %|20i", 
					      skill, 
						  SKILLS_D->GetSkillCost(skill)*3, 
						  SKILLS_D->GetSkillCost(skill)*2, 
						  SKILLS_D->GetSkillCost(skill)) });
        }
        this_player()->eventPage(tmp);
        return 1;
}

string GetHelp() {
        string tmp;
        
        tmp = "Syntax:     listskills \n";
        if (sagep(this_player())) {
          tmp += "            listskills add  \n";
          tmp += "            listskills remove \n";
          tmp += "            listskills change \n";
        }
        tmp += "Using this skill, you can display the full list of skills available on Haven. ";
        tmp += "Not all of these skills will be available from all trainers. ";
        if (sagep(this_player())) {
                tmp += "Using the add/remove/change options allow you to modify ";
                tmp += "the skills daemon.  Use this only if approved by Duuk.";
        }
        return tmp;
}

void InputSkillName(string skill) {
        this_player()->eventPrint("Now enter the cost for this skill: ");
        input_to( (: InputSkillCost, skill :) );
}

void InputSkillCost(string skill, string cost) {
        SKILLS_D->AddSkill(skill, to_int(cost));
        this_player()->eventPrint("Skill " + skill + " added with a cost of " + SKILLS_D->GetSkillCost(skill));
}

void RemoveSkill(string skill) {
        SKILLS_D->RemoveSkill(skill);
        this_player()->eventPrint("Skill " + skill + " removed.");
}

void ChangeSkillName(string skill) {
        this_player()->eventPrint("Now enter the cost for this skill: ");
        input_to( (: ChangeSkillCost, skill :) );
}

void ChangeSkillCost(string skill, string cost) {
        SKILLS_D->SetSkillCost(skill, to_int(cost));
        this_player()->eventPrint("Skill " + skill + " changed to a cost of " + SKILLS_D->GetSkillCost(skill));
}
