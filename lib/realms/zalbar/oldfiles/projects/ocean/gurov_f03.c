#include <lib.h>
#include "../forest.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetShort("a path deep into the Huntsman's Forest");
  SetExits( ([
    "northeast" : FOREST_ROOM "f02",
    "southeast" : FOREST_ROOM "f04",
//    "west"      : FOREST_ROOM "f06",
    ]) );
  SetInventory( ([
    FOREST_NPC "deer" : 1,
    ]) );
  SetLong(
    "The path becomes little more than a game trail here heading "
    "into the forest to the west. Off to the northeast and southeast "
    "the path seems to open up slightly as it leads back towards the "
    "Gurov Road. Pine trees closely guard the path into the forest "
    "and nettles lie strewn all about the path."
    );
  SetSmell("Pine sap gives the forest an earthy smell.");
  SetListen("Birds chitter from the treetops.");
  SetItems( ([
    "path" : "The path widens to east and becomes thinner to the west.",
    ({ "tree", "trees" }) : "The pine trees are green and furred.",
    ]) );
  SetItemAdjectives( ([
    "tree" : ({ "pine" }),
    ]) );
}