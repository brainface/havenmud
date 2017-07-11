/*    /cmds/player/actions.c
 *    From Nightmare LPMud
 *    Made by Mahkefel@Haven on NovSom'n, 2011
 */

#include <lib.h>
#include <daemons.h>
#include <dirs.h>

inherit LIB_DAEMON;

mapping GetAvailableActions(object player);

mixed cmd(string args) {
  object who;
  string tmp;
  mapping availableActions = ([ ]);

  if (angelp(this_player())) return "Your available actions are 'code', "
    "'write', 'debug', and 'viking bjorn'.";

  if( creatorp(this_player()) ) {
    if (!args) return "Show available actions of whom?";

    who = find_living(args);
    if (!who || who->GetInvis() > rank(this_player()))
      return "Cannot find that person or incorrect argument.";
  }

  if(creatorp(who)) return "That person can't act.";

  if(!creatorp(this_player())) who = this_player();

  availableActions = GetAvailableActions(who);

  tmp = "You know the following special manuevers: \n";

  foreach( string action in sort_array(keys(availableActions),1) ) {
    tmp += sprintf("%:-15s: %s \n",action,availableActions[action] );
  }

  this_player()->eventPrint(tmp);

  return 1;
}

string GetHelp() {
  return ("Syntax: <actions>\n\n"
    "Lists all of the special manuevers you have available "
    "due to your combat styles. Note that some verbs, such "
    "as backstab, disorient, and throw, will not be listed "
    "here even though you can use them.");
}


mapping GetAvailableActions(object who) {
  string array verbFiles;
  mapping actions = ([ ]);

  verbFiles = get_dir(DIR_ACTION_VERBS + "/*.c");

  foreach(string verbFile in verbFiles) {
    int available = 1;    
    mapping requiredSkills = ([]);
    verbFile = DIR_ACTION_VERBS + "/" + verbFile;
    //object verb = get_object(verbFile);
    requiredSkills = verbFile->GetRequiredSkills();
    foreach(string skill in keys(requiredSkills)) {
      if(requiredSkills[skill] > who->GetSkillLevel(skill)) {
        available = 0;
      }
    }
    if(available) {
      actions[verbFile->GetVerb()] = implode(keys(requiredSkills),", ");
    }
  }

  return actions;
}
