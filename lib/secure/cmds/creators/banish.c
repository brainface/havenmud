/*  A shiny new banish command
 *  This one works nicely with the new BANISH_D
 *  Duuk
 */
#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {

 if (user_exists(args)) {
  return "That name is already in use.  Too late, etc.";
  }
 BANISH_D->AddBanishedName(args);
 if (member_array(args, BANISH_D->GetBanishedNames()) == -1) {
  return "Somehow failed to banish that name.  You suck.";
  }
  this_player()->eventPrint("Successfully banished the word \"" + args + "\".");
  return 1;
}

string GetHelp(string q) {
  return    
      "Syntax: <banish [name]>\n\n"
      "Protects a name from being used by a new player.\n"
      "For example, if you have created a monster named Cassandra, in order\n"
      "to avoid problems with player complaining \"I typed 'kill\n"
      "cassandra' meaning to kill the evil enchantress, but Cassandra\n"
      "walked in and I accidentally killed her.\"  It is also to be\n"
      "used to keep people from using offensive names.\n"
    ;
}
