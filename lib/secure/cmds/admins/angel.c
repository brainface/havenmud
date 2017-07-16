/*    /secure/cmd *    from the Nightmare IV LPC Library
 *    turns a player into a creator
 *    created by Descartes of Borg 950322
 */

#include <lib.h>
#include <std.h>
#include <dirs.h>
#include <daemons.h>
#define DIR_BACKUP "/secure/save/angels/"

inherit LIB_DAEMON;

string PlayerName;

mixed cmd(string args) {
    object ob, cre_ob;
    string nom, file;

/*
    if (!duukp(this_player())) {
       return "Fuck you twat.  Ask Duuk to do it.";
    }
*/
    if( args == "" || !stringp(args) ) 
      return "Who do you want to make an Angel?";
    nom = convert_name(args);
    if( !user_exists(nom) ) return capitalize(nom) + " is not a member of " +
      possessive_noun(mud_name()) + " reality.";
    if( !strsrch(file = save_file(nom), DIR_CRES) )
      return "You cannot make "+capitalize(args)+" an Angel.";
    if( file_size(DIR_CRES+"/"+nom[0..0]) != -2) mkdir(DIR_CRES+"/"+nom[0..0]);
    if(!(ob = find_player(nom))) return "That person is not logged on!";
//  unguarded( (: cp, file + __SAVE_EXTENSION__, DIR_BACKUP + nom + __SAVE_EXTENSION__ :) );
//  unguarded( (: rename, file + __SAVE_EXTENSION__, DIR_CRES +"/" + nom[0..0] +"/" + nom + __SAVE_EXTENSION__  :) );
    cp(file + __SAVE_EXTENSION__, DIR_BACKUP + nom + __SAVE_EXTENSION__);
    rename(file + __SAVE_EXTENSION__, DIR_CRES +"/" + nom[0..0] +"/" + nom + __SAVE_EXTENSION__);
    mkdir(user_path(nom));
    unguarded( (: cp, STD_ROOM "workroom.c", user_path(nom) :) );
    if( ob = find_player(nom) ) {
        PlayerName = nom;
        catch(cre_ob = (object)master()->player_object(nom));
        PlayerName = 0;
        if( !cre_ob ) {
	    message("system", "Failed to create a cre object.", this_player());
	    message("system", "Please log out and log back in.", ob);
	    return 1;
	}
	exec(cre_ob, ob);
	cre_ob->Setup();
  cre_ob->eventMove(DIR_STANDARD_DOMAIN "/staffroom");
  cre_ob->SetReligion("None");
  cre_ob->eventPrint(
                   "Coding for Haven constitutes agreement with "
                   "all terms described in \"help immrules\" and "
                   "other immortal help documents. You will be "
                   "responsible for reading these immediately after "
                   "accepting apprentice status. Accepting these terms "
                   "constitutes acceptance of a contract of employment "
                   "between you, an employee, and Haven (Eric S "
                   "Johnson), an employer. All works coded for "
                   "Haven will remain copyright Haven per US "
                   "Code rules of copyright works for hire. Theft "
                   "of files from Haven will be punished to the full "
                   "extent of the laws of the United States of "
                   "America, the State of Michigan, "
                   "and all applicable international conventions. "
                   "The rules described herein are subject to change "
                   "without notice, with or without cause, and without "
                   "a seperate work agreement needing to be noted."
                   );
  cre_ob->eventPrint(
                     "%^MAGENTA%^If you do not accept these terms, "
                     "notify an Arch immediately.%^RESET%^"
                     );
  ob->eventDestruct();
	message("system", "You are now an Angel.", cre_ob);
  CHAT_D->eventSendChannel("ANGEL_CMD", "imm", 
          "%^BOLD%^RED%^" + cre_ob->GetCapName() + " has been raised into the ranks of "
          "the Immortals!%^RESET%^"
          );
  if (file_size(file+__SAVE_EXTENSION__) > -1) {
      unguarded( (: rename, file+__SAVE_EXTENSION__, DIR_BACKUP + file 
                  + __SAVE_EXTENSION__ :) );
       }
    }
  unguarded( (: log_file, "secure/angel", 
                capitalize(previous_object()->GetKeyName())+" made "+
                capitalize(args)+" an Angel on "+ctime(time())+".\n" :) );
  message("system", "You make " + capitalize(args) + " an Angel.",
    previous_object() );
  cre_ob->SetShort("$N the Angel");
  cre_ob->SetPosition(2);
  return 1;
}

string GetKeyName() { return PlayerName; }
