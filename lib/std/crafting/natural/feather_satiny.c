//Illura@Haven, Aug 2011
//Satiny Feather for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("satiny feather");
  SetShort("a long satiny feather");
  SetId( ({"feather"}) );
  SetAdjectives( ({ "satiny", "long" }) );
  SetLong("This large tail feather has a beautiful sheen.");
  SetMass(1);
  SetValue(2);
}
