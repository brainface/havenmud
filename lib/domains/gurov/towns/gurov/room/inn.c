#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;
inherit LIB_TOUCH;

static void create() {
  ::create();
  SetExits( ([
    "out" : GUROV_ROOM "cr4",
    ]) );
  SetShort("the Gurov Smithy");
  SetLong(
    "The smithy is dominated by an immense forge in the middle of the "
    "room. Built to withstand temperature enough to melt metal, the "
    "construction of the forge cannot be doubted. Arranged around the "
    "forge are the various tools of the smith's trade."
    );
  SetTouch("The forge's heat makes the smithy uncomfortable.");
  SetWarmth(100);
  SetClimate("indoors");
  SetAmbientLight(55);
  SetSmell("Soot and other flame-related smells come from the forge.");
  SetListen("The crackle of the flames is a dull roar.");
  SetItems( ([
    "forge" : "The forge is a heavy stone furnace designed to melt metal.",
    ({ "tool", "tools", "billows", "hammer" }) : "The tools of the forge, "
              "such as the billows and hammer, are lined up near the forge.",
    ]) );
  SetInventory( ([
    ]) );
}