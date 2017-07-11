#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("in the main foyer");
  SetLong(
          "The foyer of the tower has been built miraculously. The "
          "walls bend to the doorway to the east and to the south "
          "leading outside the tower. A simple blood red carpet "
          "lines the ground free of any dirt or furniture. In the "
          "center of this circular room is a human skull on a "
          "small column glowing in black flame. The dark fog "
          "from the outside has not crept inside and the torches "
          "glow in black flames.");

  SetInventory( ([ 
                  TOWER_OBJ "skull" : 1,
				  TOWER_OBJ "rtorch" : 3,
              ]) );
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The skull crackles and snaps in flame."
           ]) );
  SetItems( ([
     "ceiling"   : "The ceiling is flat and bare. It is composed "
                   "of black stone cut slabs.",
     "torches"   : "Torches burn in black flame, making this "
                   "tower dampen the light here. They line "
                   "the walls three feet apart from each other.",
     "doorway"   : "It is to the south, leading outside the "
                   "black tower. ",
     "walls"     : "The tower wall is made of perfectly cut black "
                   "stone slabs.",
     "column"    : "It is made of stone and holds a skull on top of "
                   "it.",
    ({ "ground", "floor" }) : "The ground has been lined with a "
                               "red carpet and it lines the walls "
                               "edge to edge.",
    ({ "carpet"  }) : "The red carpet is plain and "
                      "simple. It covers the floor "
                      "wall to wall.",
              ]) );
  SetItemAdjectives( ([
    "ceiling" : ({ "flat","bare","stone" }),
    "carpet" : ({ "red" }),
    "floor" : ({ "carpet","red" }),
    "ground" : ({ "carpet","red" }),
    "walls" : ({ "black","stone"}),
    "column" : ({ "stone" }),
    "slabs" : ({ "cut","black","stone" }),
   ]) );
  SetExits( ([
            "out"            : TOWER_ROOMS "tout04",
            "east"           : TOWER_ROOMS "twer02",
           ]) );
  SetDoor("out",TOWER_OBJ "door");
  }


