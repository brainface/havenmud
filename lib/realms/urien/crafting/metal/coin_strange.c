//Illura@Haven, Aug 2011
//Strange Old Coin for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("strange coin");
  SetShort("a strange old coin");
  SetId( ({"coin"}) );
  SetAdjectives( ({ "strange", "old" }) );
  SetLong("The two sides of this coin show faces you don't recognize, perhaps some heroes out of antiquity. The milled edges are smooth in places from being passed through many hands.");
  SetMass(1);
  SetValue(7);
}
