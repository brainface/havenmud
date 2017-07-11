#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("before an iron door");
  SetAmbientLight(35);
  SetExits( ([
    "east"  : "3-1",
    "north" : "3-5",
    ]) );
  SetSmell( ([
    "default" : "The smell of torches burning poisons the air.",
    ]) );
  SetListen( ([
    "default" : "A terrible cry of the damned comes from the north.",
    ]) );
  SetInventory( ([
   TOWER_NPC "skull" : random(4) + 1,
    ]) );
  SetLong("The hallway ends here before a huge iron doorway. Back to "
          "the east, the hallway opens into a three way intersection. "
          "The room here though is a stone marvel of seamless build "
          "and exquisite detail. Torches line the walls in a way that "
          "makes this room much brighter than most in the tower.");
  SetDoor("north", TOWER_OBJ "door35");
  call_other( TOWER_OBJ "door35", "SetClosed", 1);
  call_other( TOWER_OBJ "door35", "SetLocked", 1);
}
