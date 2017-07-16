//Illura@Haven, Aug 2011
//Woolen Swatch for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("woolen swatch");
  SetShort("a swatch of woolen felt");
  SetId( ({"swatch", "felt"}) );
  SetAdjectives( ({ "woolen" }) );
  SetLong("This is a swatch of wool felt, matted with wear. It seems scratchy but pretty durable.");
  SetMass(1);
  SetValue(1);
}

