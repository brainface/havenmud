//Illura@Haven, Aug 2011
//Sterling Filum for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("sterling filum");
  SetShort("a sterling filum");
  SetId( ({"filum"}) );
  SetAdjectives( ({ "sterling" }) );
  SetLong("The looped filament of rustless sterling silver shows no sign of age or wear, just a gentle, quiet beauty.");
  SetMass(2);
  SetValue(8);
}
