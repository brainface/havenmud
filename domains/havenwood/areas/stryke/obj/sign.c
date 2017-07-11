/* A warning sign */
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sign");
  SetShort("a warning sign");
  SetLong("This is a wooden sign listing something.");
  SetRead("default",
    "Know ye that on this spot on the  \n"
    "12th day of Fifthmonth, 103, three bold and brazen \n"
    "Adventurers went into the mound to slay the dragon \n"
    "known as Stryke.  \n\n"
    "Of them, only one lived to tell the tale. \n"
    "RIP:  Zorander, Cyric, and Kudos to Zane, the Survivor.");
 SetPreventGet("You cannot take that!");
  }
