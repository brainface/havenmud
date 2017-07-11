//Illura@Haven, Aug 2011
//Nacreous Shell for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("nacreous shell");
  SetShort("a nacreous shell");
  SetId( ({"shell"}) );
  SetAdjectives( ({ "nacreous" }) );
  SetLong("This shell is sheathed in mother-of-pearl, which glimmers in a rainbow of colors.");
  SetMass(1);
  SetValue(4);
}
