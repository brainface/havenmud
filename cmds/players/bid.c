#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string arg) {
  int amount;
  string curr;
  object env = environment(this_player());
  if (!userp(this_player())) {
    this_player()->eventCollapse();
    this_player()->eventDie(STD_OBJ "dummy/falling");
    return 1;
  }
  if (!arg) {
    env->CanBid(this_player(), 0);
    this_player()->eventPrint("Use \"bid <amount>\" to place a bid if this building is for sale.");
    return 1;
  }
  if (sscanf(arg, "%d %s", amount, curr) != 2) {
    if (!amount = to_int(arg)) {
      this_player()->eventPrint("Bid how much?");
      return 1;
    }
  }
  if (!curr) curr = env->GetLocalCurrency();
  if (!curr) {
    this_player()->eventPrint("This area is not for sale.");
    return 1;
  }
  if (curr != env->GetLocalCurrency()) {
    this_player()->eventPrint("Bids on this building must be in " + env->GetLocalCurrency() + ".");
    return 1;
  }
  if (!env->CanBid(this_player(), amount)) {
    this_player()->eventPrint("You cannot place that bid here.");
    return 1;
  }
  env->eventBid(this_player(), amount);
  return 1;
}

string GetHelp(string u) {
  return  "Syntax:     bid AMOUNT \n"
          "            bid AMOUNT CURRENCY\n\n"
          "This command enters a bid on a building. This command does NOT "
          "check whether you are carrying that amount, nor does it check if "
          "you are even WORTH that amount of currency.  Be aware that when the "
          "auction is over, if you are unable to back up your bid, the town officials "
          "will likely be VERY unhappy.";
}
                                 