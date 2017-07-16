/*    /secure/cmds/adm/rid.c
 *    from the Dead Soulsr2 Object Library
 *    command to get rid of players 
 *    created by Descartes of Borg 951015
 */
                     
#include <lib.h>
#include <dirs.h>
#include <privs.h>

inherit LIB_DAEMON;

mixed cmd(string who) {
    object ob;
    string str, file;

    if (!securep(this_player())) return "You're not a Secure.  Dumbass.";
    if( !who || who == "" ) return "Rid whom?";
    str = convert_name(who);
    who = capitalize(who);
    if( member_group(str, PRIV_ADMIN) || member_group(str, PRIV_SECURE)) {
    	return "You're an assmonkey.";
    	}
    if( !user_exists(str) ) return "No such person: " + who + ".";
    if( ob = find_player(str) ) {
	    who = (string)ob->GetCapName();
	    message("system", "You are being ridded from " + mud_name() + ".",
		    ob);
      users()->eventPrint("%^BOLD%^RED%^The booming anger of " +
               capitalize(this_player()->GetKeyName()) + 
               " can be felt as " + nominative(this_player()) + 
               " destroys " + capitalize(ob->GetKeyName()) + "!");
	    if( !((int)ob->eventDestruct()) ) destruct(ob);
      }
    file = save_file(str) + __SAVE_EXTENSION__;
    if( rename(file, DIR_RID + "/" + str + __SAVE_EXTENSION__) ) {
	    message("system", "Rename failed, security violation logged.",
		    this_player());
	    log_file("security", "\n*****\nRid violation attempted\n"
		    "Target: " + who + "\nCall stack:\n" + 
		  sprintf("%O\n", previous_object(-1)));
	    return 1;
      }
     message("system", who + " has been ridded from " + mud_name() + ".",
	    this_player());
    return 1;
}


string GetHelp() {
  return "\n" +
"Syntax: rid <name>\n\n"
"Effect: Deletes, nukes, wipes out and annhilates unwanted player <name> "
"\nSee also: demote, promote, sponsor";
}

