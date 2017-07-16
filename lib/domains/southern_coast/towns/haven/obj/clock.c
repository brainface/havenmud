#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetShort("a well maintained clock");
  SetKeyName("clock");
  SetId( ({ "clock" }) );
  SetAdjectives( ({ "well", "maintained" }) );
  SetLong("This is a well maintained clock.");
  SetInvis(1);
  SetPreventGet("The clock is firmly mounted to the wall.");
}

varargs mixed eventShow(object who, string comp) {
  mixed tmp = ::eventShow(who, comp);
  
  who->eventPrint("It reads, \"" + mtime(time()) + "\"");
  return 1;
}