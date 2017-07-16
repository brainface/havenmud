//Illura@Haven, Aug 2011
//Silk Scrap for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("silk piece");
  SetShort("a piece of old silk");
  SetId( ({"piece", "silk"}) );
  SetAdjectives( ({ "old" }) );
  SetLong("This lovely, soft piece of old silk may have been an elegant scarf at one time, but is now frayed and faded with use.");
  SetMass(1);
  SetValue(1);
}

