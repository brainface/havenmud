/*  A tent for a fighter leader */
#include <lib.h>
#include "../../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(23);
  SetShort("inside a dim tent");
  SetObviousExits("out");
  SetExits( ([
     "out" : GOBLIN_ROOM + "m_7",
     ]) );
  SetInventory( ([
      GOBLIN_NPC + "fighter" : 1,
      GOBLIN_NPC + "trainer" : 1,
     ]) );
  SetProperty("no bump", 1);
  SetLong("The inside of this tent is filled with the aftermath of a "
          "large gathering of goblins. Overturned mats and small torn "
          "pillows make this room look like the center of a great battle.");
  SetItems( ([
       ({ "pillow", "pillows" }) : "The pillows look ripped beyond repair.",
        ({ "mat", "mats" }) : "The mats look tossed about in fury.",
      ]) );
  SetSmell( ([
    "default" : "The smell in here is enough to make a normal person vomit.",
      ]) );
  SetListen( ([
     "default" : "The room is fairly quiet.",
     ]) );
  }
