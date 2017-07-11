//Bug Report 1179, typo fix.

#include <lib.h>
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetObviousExits("north, south, west");
  SetShort("along the main path");
  SetLong(
    "The path continues into the village to the south, and leads "
    "north back to the main Haven Road.  Off to the south, there "
    "appears to be a split in the path leading to different sections "
    "of the village. There is a large leather tent here."
    );
  SetItems( ([
    "tent" : "This tent is made of sturdy leather.",
    ]) );
  SetEnters( ([
    "tent" : GOBLIN_DIR "/leatherstore/leatherstore",
    ]) );
  SetExits( ([
     "west" : GOBLIN_ROOM + "w_1",
     "north" : GOBLIN_ROOM + "m_1",
     "south" : GOBLIN_ROOM + "m_3",
    ]) );
  SetInventory( ([
      GOBLIN_NPC + "slash_medium" : 1,
    ]) );
  }
