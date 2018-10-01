//Illura@Haven, Aug 2011
//Brass Fitting for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;
static void create() {
  ::create();
  SetKeyName("brass fitting");
  SetShort("a brass fitting");
  SetId( ({"fitting"}) );
  SetAdjectives( ({ "brass" }) );
  SetLong("A dull brass piece of angled metal that is all but worthless on its own.");
  SetMass(1);
  SetValue(1);
}
