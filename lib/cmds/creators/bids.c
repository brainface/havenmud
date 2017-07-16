#include <lib.h>
#include <config.h>
#include <save.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

int Bid;
string Bidder;
string *Owners;

mixed cmd() {
  this_player()->eventPrint(sprintf("%-25s %-15s %-15s", "Id", "Bidder", "Bid"));

  foreach(string file in get_dir(SAVE_ESTATES + "/"))  {
    sscanf(file, "%s.o", file);
    restore_object(SAVE_ESTATES + "/" + file);
    if (sizeof(Owners)) continue;
    this_player()->eventPrint(sprintf("%-25s %-15s %-15d", file, Bidder, Bid));
  }

  return 1;
}

string GetHelp(string u) {
  return "Syntax: <bids> \n\n"
         "Shows bidding information on unowned houses and inns.";
}
