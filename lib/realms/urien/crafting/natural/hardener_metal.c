//Illura@Haven, Aug 2011
//Metal Hardener for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("metal hardener");
  SetShort("a glob of metal hardener");
  SetId( ({"glob", "hardener"}) );
  SetAdjectives( ({ "metal" }) );
  SetLong("This white viscous gel can be rubbed on various metals to make them harder.");
  SetMass(1);
  SetValue(1);
}
