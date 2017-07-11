/* Barracks */
#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(15);
  SetClimate("indoors");
  SetShort("a dark warrior hall");
  SetExits( ([
    "out" : GWONISH_ROOM "gw13",
    ]) );
  SetSmell( ([
    "default" : "The stench of weapon oil and rotting scales assaults the nostrils.",
    ]) );
  SetLong(
    "Thick wooden planks make up the walls of the training hall in Gwonish. "
    "Tossed around the room are various bent, distorted weapons, some makeshift, "
    "some obviously stolen. The hard wooden floor is little more than enough to "
    "cover the swamp, and muck seeps in between the planks in many places. A "
    "small opening serves as a window, looking out into the swamp."
    );
  SetInventory( ([
    GWONISH_NPC "smithy"  : 1,
    GWONISH_NPC "fighter" : 1,
    GWONISH_NPC "tenquax" : 1,
    ]) );
  SetItems( ([
    ({ "plank", "planks" }) : "The planks are poorly fitted wood that barely "
                              "seems enough to hold together.",
    ({ "floor" }) : "The floor is made up of wooden planks that allow some muck "
                    "to seep in from the swamp.",
    ({ "weapon", "weapons" }) : "The weapons are in disarrary and are all but useless.",
    ({ "muck" }) : "The muck is swamp goo that has seeped up through the floor.",
    ]) );
  SetItemAdjectives( ([
    "plank" : ({ "hard", "wooden", "thick" }),
    "floor" : ({ "hard", "wooden", }),
    "weapon" : ({ "bent", "distorted", "makeshift", "stolen" }),
    ]) );
}
  
