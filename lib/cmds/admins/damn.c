/*  Damn Cmd
 */

#include <lib.h>
#include <rooms.h>

inherit LIB_HELP;
inherit LIB_DAEMON;

mixed cmd(string args)
{
  object target;
  if (!args) return "Damn whom?";
  if (!(target = find_player(args))) return "No such target.";
  if (creatorp(target) && !archp(this_player()))
    return "Send an Immortal to hell?";
  target->eventMoveLiving(ROOM_HELL);
  send_messages("look",
       "$agent_name $agent_verb down upon "
       "the world of Kailie.",
       this_player(), 0, users() - ({ this_player() }) );
  send_messages("boom",
     "$agent_nominative%^RED%^%^BOLD%^ $agent_verb%^RESET%^ across "
     "the world in unspeakable %^RED%^%^BOLD%^anger!%^RESET%^",
     this_player(), 0, users() - ({ this_player() }) );
  send_messages("send",
     "$agent_name $agent_verb%^RED%^BOLD%^ $target_name %^RESET%^"
     "to%^RED%^%^BOLD%^ hell!%^RESET%^",
       this_player(), target, users() - ({ this_player(), target }) );
  if (playerp(target))
  unguarded( (: log_file,
       "damned",
     capitalize(this_player()->GetKeyName()) + " damned " + 
     capitalize(target->GetKeyName()) + " " + ctime(time()) + "\n" :) );
  return 1;
}

string GetHelp()
{
  return "Syntax :  <damn [player]>  \n\n"
         "Sends a player to Hell.  Not a nice place to be. Hell will "
         "prevent mortals from using: tell, reply, wizhelp or the ooc "
         "channel. They can use pray to see redemption.";
}
