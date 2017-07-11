//Illura@Haven, Aug 2011
//Wire for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("wire length");
  SetShort("a length of strong wire");
  SetId( ({"length", "wire"}) );
  SetAdjectives( ({ "strong" }) );
  SetLong("This is a length of coiled wire, burnished and softly shining.");
  SetMass(1);
  SetValue(3);
}
