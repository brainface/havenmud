
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetShort("an ice clock");
  SetKeyName("clock");
  SetId( ({ "clock" }) );
  SetAdjectives( ({ "ice" }) );
  SetLong("This clock is completely made of ice.");
  SetPreventGet("The clock is magically sealed to the desk!");
  SetInvis(1);
}

varargs mixed eventShow(object who, string comp) {
  mixed tmp = ::eventShow(who, comp);
  who->eventPrint("It reads, \"" + mtime(time()) + "\"");
  return 1;
}