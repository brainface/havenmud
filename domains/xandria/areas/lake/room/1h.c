//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside a weaver's workshop");
  SetClimate("indoors");
  SetLong(
    "Inside this building are rows and rows of bolts of fabric, "
    "threads, and bundles of wool and flax. Only enough of the "
    "tiled floor remains to form a walkway and an area for the "
    "massive looms the weaver uses to create her masterpieces. "
    "A doorway leads out, and another to the south. "
  );
  SetItems( ([
    ({ "bolts", "bolt", "fabric", "thread", "threads" }) :
    "The number of bolts of fabric and threads is so great you "
    "scarcely think you could count it all. There are many shades "
    "and styles, but most are fine and snowy white.",
    ({ "bundle", "bundles", "wool", "flax" }) :
    "The bundles of wool and flax are just begging to be turned "
    "into fabric.",
    ({ "floor", "walkway" }) : 
    "The walkway is enough space to get one through the room.",
    ({ "loom", "looms" }) : 
    "The looms are gigantic, some containing half-finished pieces "
    "of linen or woolen fabric.",
  ]) );
  SetItemAdjectives( ([
  "floor" : ({ "tiled" }),
  "looms" : ({ "massive" }),
  ]) );
  SetInventory( ([
    LAKE_NPC "hauhet" : 1,
  ]) );
  SetListen("Chatter comes from the southern room.");
  SetSmell("It smells like clothes.");
  SetExits( ([
    "south"  : LAKE_ROOM "/2h",
    "out" : LAKE_ROOM "/1g",
  ]) );
}
