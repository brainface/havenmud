//      /bin/adm/_addguest.c
//      from the Dead Souls Mudlib
//      adds a person to the guest list for when the mud is locked
//      created by Descartes of Borg 08 july 1993

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
  if(!args) {
    return ("Correct syntax: addguest [guestlist]\n");
    }
  BANISH_D->AddGuest(args);
  if (member_array(args, BANISH_D->GetGuests()) == -1) {
    return "You somehow managed to fail.  Nicely done.";
  }
  this_player()->eventPrint("Successfully made " + args + " a guest.");
  return 1;
}

void help() {
    message("help",
      "Syntax: <addguest [player list]>\n\n"
      "Adds a single player or group of players to the database of guests "
      "allowed onto the mud when it is locked.  This is generally used to "
      "allow people in who are not in any of the groups defined in "
      "LOCKED_ACCESS_ALLOWED or to allow on player testers.\n\n"
    "See also: removeguests, whoguests", this_player()
    );
}
