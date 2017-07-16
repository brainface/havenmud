//Illura@Haven, Aug 2011
//Powdered Sulfur for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("powdered sulfur");
  SetShort("a handful of powdered sulfur");
  SetId( ({"handful", "sulfur"}) );
  SetAdjectives( ({ "powdered" }) );
  SetLong("The sulfur powder is canary yellow and gives off an odor like burnt breakfast.");
  SetMass(1);
  SetValue(1);
}
