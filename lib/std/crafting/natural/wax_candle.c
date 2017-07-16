//Illura@Haven, Aug 2011
//Candle Wax for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("candle wax");
  SetShort("a stub of candle wax");
  SetId( ({"stub", "wax"}) );
  SetAdjectives( ({ "candle" }) );
  SetLong("An oily bit of yellow tallow from a cheap candle.");
  SetMass(1);
  SetValue(1);
}
