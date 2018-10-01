
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetShort("a clock");
  SetKeyName("clock");
  SetId( ({ "clock" }) );
  SetAdjectives( ({ "wall" }) );
  SetLong("This wall clock rests on the north wall.");
  SetPreventGet("The clock is firmly mounted to the wall.");
  SetInvis(1);
}

varargs mixed eventShow(object who, string comp) {
  mixed tmp = ::eventShow(who, comp);
  
  who->eventPrint("It reads, \"" + mtime(time()) + "\"");
  return 1;
}
