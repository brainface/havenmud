/* 5/03 Libitina /newbie area/ wooded vale */


#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "Sunlight shines down on the small clearing here. Grass grows " 
      "but is kept neatly trimmed by the local wildlife. A tiny creek "
      "trickles by to the north, while a small path leads southeast. "
      "The main path travels south from here, away from the water."
    );
    SetItems( ([
      "clearing" : "Only about eight feet in diameter, its quite a "
      "small area."
      "It must be rather popular though because of the creek.",
      "grass" : "Yellow-green grass grows neatly, kept a short "
      "length by deer and other animals.",
      /*"creek" : "This little gurgling creek is only about a foot wide, "
      "and may be six inches deep, just enough to provide a refreshing drink.",*/
      ({ "path", "trail" }) : "The path to the southeast is overgrown, but "
      "recently trampled. The trail to the south looks like it's used "
      "by several creatures."
      ]) );
    SetInventory( ([
      WOOD_OBJ "water.c" : 1,
      WOOD_NPC "rabbit.c" : 1 ]) );
    SetSmell("default", 
      "The air smells crisp, and clean."
      );
    SetListen("default", 
      "The creek gurgles happily."
      );
    SetExits( ([
      "south"     : WOOD_ROOM "vale5.c",
      "southeast" : WOOD_ROOM "vale4.c"
      ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}
