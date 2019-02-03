/*
 * soulhelp.c
 * previews emote text for emote testing
 * mahk 2018
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string arg)
{
  object soul;
  string message;
  object who = this_player();
  int gave_output = 0; 
  
  if (!SOUL_D->GetEmote(arg)) {
    return "That is not a real emote. Are you sure it's not a verb?";    
  }
  soul = SOUL_D->GetEmote(arg);

  if (soul->GetMessage("")) {
    send_messages(soul->GetMessageVerbs(""), soul->GetMessage(""),
      who,0,0);
    gave_output = 1;
  }
  
  if (soul->GetMessage("LIV")) {
    send_messages(soul->GetMessageVerbs("LIV"), soul->GetMessage("LIV"),
      who,who,0);
    gave_output = 1;
  }

  if (!gave_output) {
    who->eventPrint("Something's funky about this emote. Bug report it.");  
  }
  
  return 1;
}

string GetHelp()
{
   return ("Syntax: <soulhelp [emote name]>\n"
           "Displays a preview of an emote's text, targeting you.");
}

