//Illura@Haven, Aug 2011
//Antique Hilt for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("antique hilt");
  SetShort("an antique hilt");
  SetId( ({"hilt"}) );
  SetAdjectives( ({ "antique" }) );
  SetLong("An old sword hilt, broken off at the blade. The stones have been pried out by former owners, but the metal workmanship is still good. Perhaps it could be of some use.");
  SetMass(1);
  SetValue(6);
}
