#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Parvan Town Hall");
  SetExits( ([
    "out"   : PARVA_ROOM "path1",
    "north" : PARVA_ROOM "mayor",
    "east"  : PARVA_ROOM "newbie",
    "west"  : PARVA_ROOM "treasury",
    "up"    : PARVA_ROOM "post_office",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetNewsgroups( ({ "town.parva" }) );
  SetLong(
    "The inside of the town hall does not give great relief to those scared "
    "by the state of disrepair in the rest of Parva. The main hallway seems "
    "infrequently travelled. A stairway leads up to another level, and halls "
    "lead off to the north, west, and east. A pictographic sign sits in the "
    "middle of the room, detailing the contents of the rest of the hall."
    );
  SetSmell("The town hall smells of a strange mix of rum and vomit.");
  SetItems( ([
    ({ "stairs", "stairway" }) : "The stairway leads up to the Parva post.",
    "sign" : "The sign has images of coins (with an arrow west), a child "
             "(east), and a crown (north).",
    ]) );
  SetInventory( ([
    PARVA_NPC "combat_trainer" : 1,
    PARVA_NPC "fighter_leader" : 1,
    ]) );
}
  