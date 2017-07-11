/*    /secure/cmds/admins/link.c
 *    from the Dead Souls V Object Library
 *    link SECONDARY to PRIMARY
 *    link PLAYER
 *    link
 *    created by Descartes of Borg 951216
 */

#include <lib.h>
#include <link.h>
#include <daemons.h>
#include <message_class.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
  mixed tmp;
  string character, email;

  if( !archp(previous_object()) ) return 0;

  if( !args || args == "" ) {
    mapping links;
    string formatString;
    int screenSize = ((int *)this_player()->GetScreen())[0];
    int playerSize = ((screenSize * 4) / 16) -1;
    int emailSize = ((screenSize * 6) / 16) - 1;
    int lastOnSize = ((screenSize * 6) / 16) - 1;

    if(playerSize < 14) playerSize = 14;
    if(emailSize < 25) emailSize = 25;
    if(lastOnSize < 25) lastOnSize = 25;

    formatString = "%:-" + playerSize + "s %:-" + emailSize
      + "s %:-" + lastOnSize + "s";

    tmp = ({ center("%^CYAN%^  " + mud_name()
      + " Approved Character Links%^YELLOW%^", screenSize) });
    
    tmp += ({ sprintf(formatString, "Player", "", "Last On%^RESET%^") });

    links = (mapping)CHARACTER_D->GetLinks();
    foreach(email in sort_array(keys(links), 1)) {   
      class char_link l;
	    int maxi;
      l = links[email];
      if( !(maxi = sizeof(l->Characters)) ) continue;
      tmp += ({ email });
      foreach(string pl in l->Characters)
        tmp += ({ sprintf(formatString, "  " + capitalize(pl), "", ((l->LastOnWith == pl) ? ctime(l->LastOnDate) : "(not last)")) });
	}
	this_player(1)->eventPage(tmp, MSG_SYSTEM);
	return 1;
  }
  
  if( sscanf(args, "%s to %s", character, email) != 2 ) {
    return "Link who to what email?";
  }  
  if( !email || email == "" ) {
     return "Invalid email!";
    }
   tmp = (mixed)CHARACTER_D->eventLink(email, character);
   if( !tmp ) this_player(1)->eventPrint("Fucking Failed!");
   if( tmp == 1) this_player(1)->eventPrint("Linked.", MSG_SYSTEM);
     else this_player(1)->eventPrint(tmp, MSG_SYSTEM);
   return 1;
}

string GetHelp(string str) {
    return ("Syntax: <link SECONDARY to PRIMARY>\n"
	    "        <link PLAYER>\n"
	    "        <link>\n\n"
	    "In the first form, it allows you to mark two characters "
	    "as being controlled by the same real individual.  It "
	    "creates a relationship where one character is considered "
	    "primary, and the other is secondary.  If link relationships "
	    "already exist for one or more, this will alter those "
	    "and create a new one with the primary one you specify as "
	    "primary.  For example, if both characters were already set "
	    "up as primary links, the one you specify with this command "
	    "as primary becomes the sole primary link for these characters, "
	    "and the secondary plus its secondaries all become secondaries "
	    "fot his primary.\n\n"
	    "If you just pass a player name as an argument, this command "
	    "will show you the link information on that player.\n\n"
	    "If you give no arguments, then this command will list all "
	    "known links/\n\n"
	    "See also: finger, unlink");
}
