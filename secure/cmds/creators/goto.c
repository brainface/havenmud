/*    /cmds/creator/goto.c
 *    from the Nightmare IV LPC Library
 *    a command to take a cre anywhere in the game
 *    created by Descartes of Borg 930906
 *    modified for NM IV 950331
 *    Modified by Zedd@Haven to not suck.  Better, cleaner invis checking
 *      used.  May 13, 99
 */

#include <lib.h>

inherit LIB_DAEMON;
inherit LIB_HELP;
 
static void create() {
  daemon::create();
  help::create();
}

mixed cmd(string str) {
  object ob;

  if(!str) return "Goto where?";
  if (ob = find_living(lower_case(str))) {
    if (ob->GetInvis() > rank(this_player())) ob = 0;
    else ob = environment(ob);
  }
  if(!ob) str = absolute_path((string)this_player()->query_cwd(), str);
  if (!ob && !file_exists(str + ".c") && strsrch(str, "virtual") == -1) 
    return "No target object.";
  if (!ob) (ob = find_object(str));
  if (!ob) (ob = unguarded( (: load_object, str :) ) );
  if(ob) {
    this_player()->eventMoveLiving(ob, "");
    return 1;
  }
  this_player()->eventPrint("Failed to find specified object in goto.");
  return 1;
}

string GetHelp(string blah) {
  return 
      "Syntax: <goto [living thing|file]>\n\n"
      "This command will move you to where the living thing is if it can "
      "be found, otherwise it will search for the file named and try to "
      "move you into that file.\n\n"
      "See also: home, move, trans.\n"
      "NOTE:  You can no longer use the .c in goto.";
}
