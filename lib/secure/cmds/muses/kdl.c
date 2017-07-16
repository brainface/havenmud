/*
 * Kill Dead Logins
 * Coded by a very bored Zeddicus@Haven on 11/11/1999 1:42AM.
 */

#include <lib.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

static void create()
{
   SetHelp("Syntax: <kdl>\n\n"
           "Kills Dead Logins (KDL).");
}

mixed cmd(string str)
{
  int count;
  
  foreach(object ob in filter(users(), (: !($1->GetName()) :)))
  {
    if (query_idle(ob) >= 30)
    {
      destruct(ob);
      count++;
    }
  }
  return capitalize(consolidate(count, "one dead login") + " killed.");
}
