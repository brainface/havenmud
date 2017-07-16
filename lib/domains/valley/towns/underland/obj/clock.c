#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetShort("a massive stone clock");
  SetKeyName("clock");
  SetId( ({ "clock" }) );
  SetAdjectives( ({ "massive", "stone" }) );
  SetLong(
    "This massive stone clock sits at the Crossroads in Underland, intoning "
    "the passage of time here in the Land Under the Mountains."
    );
  SetMass(100000000);
}

varargs mixed eventShow(object who, string comp) {
  mixed tmp = ::eventShow(who, comp);
  
  who->eventPrint("It reads, \"" + mtime(time()) + "\"");
  return 1;
}