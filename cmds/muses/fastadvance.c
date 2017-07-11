#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object who;
  int level;
  string *parsed = ({ });
  
  if (!args) {
    return "fastadvance who skill-level";
  }
  if (!musep(this_player())) {
    return "Sorry, I don't trust you with that.";
  }
  parsed = explode(args, " ");
  args = parsed[0];
  if (sizeof(parsed) == 2) level = to_int(parsed[1]);
    else level = 604;
  who = find_player(args);
  if (!who) {
    return "Can't find anyone named \"" + args + "\".";
  }
  if (!who->GetTestChar()) {
    return "This can only be used on test chars.";
  }
  foreach(string sk in who->GetSkills()) { 
    who->SetSkill(sk, level, who->GetSkillClass(sk));
    who->ResetLevel();
  }
  this_player()->eventPrint("Fast advanced " + who->GetCapName());
  return 1;
}

string GetHelp(string u) {
  return "Syntax:   fastadvance <player> <level>\n\n"
         "Use this command to fast advance a single test character. "
         "Nicer than using a complex eval, yes?";
}
        
  
