//Illura@haven
//d7
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("the great oil ocean");
  SetLong(
    "The slippery sands are rimmed with towering blazes here, the fires "
    "testament to the hazardous flammability of the ground. Perhaps "
    "these long-burning fires were lit by hapless adventurers, or "
    "lightning once struck the barren landscape. Either way, the heat "
    "is intense, and the smoke is thick and choking."
  );
  SetExits( ([
    "north" : OIL_ROOM "/d6",
    "south" : OIL_ROOM "/d8",
    "west" : OIL_ROOM "/c7",
    "east" : OIL_ROOM "/e7",
  ]) );
  SetItems( ([
    ({"oil", "sand", "sands"}) : "The oil ocean is composed of shifting dark sand and swirling oils, layered with water from the true ocean to the far west.",
    ({"blazes", "blaze", "fire", "fires"}) : "The fires burn hot and long, issuing forth deep black smoke.",
    ({"landscape"}) : "The oil ocean is desolate and unremarkable.",
    ({"smoke"}) : "The fires give off a great deal of black, roiling smoke."
  ]) );
  SetItemAdjectives( ([
    "sands" : ({"slippery"}),
    "blazes" : ({"towering"}),
    "smoke" : ({"thick", "choking"})
  ]) );
  SetInventory( ([
    OIL_NPC + "creature" : 4,
  ]) );
  SetListen( ([
    "default" : "Fires crackle and sputter around you here.",
  ]) );
  SetSmell( ([
    "default" : "Nauseating smoke clots the otherwise acrid air.",
  ]) );
}
