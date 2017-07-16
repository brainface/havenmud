//Illura@Haven, Aug 2011
//Coarse String for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("coarse thread");
  SetShort("a length of coarse thread");
  SetId( ({"length", "thread"}) );
  SetAdjectives( ({ "coarse" }) );
  SetLong("This a tangled, coarse thread. It doesn't slip through your fingers easily.");
  SetMass(1);
  SetValue(1);
}

