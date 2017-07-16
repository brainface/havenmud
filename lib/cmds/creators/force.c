/*    /cmds/creators/force.c
 *    From the Nightmare V Object Library
 *    Created by Descartes of Borg 961018
 *    Version: %A%
 *    Last modified: %D%
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;
string GetErrorMessage();
string GetHelp();

mixed cmd(string args) {
    object who = previous_object();
    object target;
    string name, cmd;

  if (angelp(this_player())) return 0;
  if (!immortalp(who)) return "Sorry, Immortals or above!";
    if(!stringp(args))
        return notify_fail(GetErrorMessage()+"\n");

    if( sscanf(args, "%s to %s", name, cmd) == 2 ) {
    if(present(name,environment(who))) 
       if(living(present(name, environment(who)))) {
       target = present((name),environment(who));
       } else {
        if( find_living(lower_case(name)) ) {
            target = find_living(lower_case(name));
        }
      }
        if( !target ) {
            who->eventPrint("Cannot find any living thing called: " + name);
            return 1;
        }
    }
    else {
        return notify_fail(GetHelp()+"\n");
    }
  if (!archp(this_player()))
  unguarded( (: log_file, 
      "forces",
     capitalize(this_player()->GetKeyName()) + " forced " + args + " " +
     ctime(time()) + "\n" :) );

    who->eventPrint("You force " + target->GetShort() + " to: " + cmd);

    target->eventForce(cmd);
  if ((noncreatorp(target)) && (!target->GetTestChar()) && (!archp(this_player()))) {
  CHAT_D->eventSendChannel("Force Report", "reports",
      capitalize(this_player()->GetName()) + " forced "
      +target->GetShort()+" to "+cmd);
  }
  return 1;
}

string GetErrorMessage() {
    return "Force whom to do what?";
}

string GetHelp() {
    return ("Syntax: <force LIVING to COMMAND>\n\n"
            "Allows you to force a living object to take a certain action.");
}
