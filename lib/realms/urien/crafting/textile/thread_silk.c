//Illura@Haven, Aug 2011
//Heavy Silk String for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("heavy string");
  SetShort("a heavy silken string");
  SetId( ({"string"}) );
  SetAdjectives( ({ "heavy", "silken" }) );
  SetLong("This gossamer plait of silken strands slides through your fingers with great ease. Made taut, it would cut through skin without too much trouble.");
  SetMass(1);
  SetValue(1);
}

