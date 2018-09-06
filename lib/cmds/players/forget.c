/*  /cmds/players/forget
 *  Allows a player to let their character forget knowledge
 *  of a spell or song
 *  created by Dylanthalus@Haven on May 11th, 1999
 *  (his very first command)
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {

  object who = this_player();

  if( !sizeof(str) )
    return "Syntax: forget <spell>\n"
           "        forget <song>\n";

  if (who->GetForced())
    return "You cannot be forced to forget.",

  str = lower_case(str);
  if (member_array(str, keys(who->GetSpellBook())) != -1) {
    who->eventForgetSpell(str);
    who->eventPrint("You forgot " + str + "!");
    return 1;
    }
   else if (member_array(str, keys(who->GetSongBook())) != -1) {
    who->eventForgetSong(str);
    who->eventPrint("You forgot " + str + "!");
    return 1;
    }
  else {
    return "You cannot forget knowledge that you do not possess.";
  }
}

string GetHelp() {
   return ("Syntax: forget <spell>\n"
    "This commands enables a player to allow their character to forget the "
    "knowledge of a spell or song.\n\n"
    "See also: spells, songs");
}


/* Approved by Duuktsaryth on Wed May 12 19:13:54 1999. */

