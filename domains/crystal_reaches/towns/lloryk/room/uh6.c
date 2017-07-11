#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a bend in the road");
  SetLong("Heroes Lane ends here and a smaller road curves north "
          "and leads further into the heart of town. Further north, "
          "many small buildings line the path, but the wooden "
          "building sitting by the eastern side of the road here "
          "seems to be the most used. Off to the west is "
          "a small intersection which links Heroes Lane to the "
          "southern gate of the Shire. The rolling hills of the "
          "Shire spread out to the west, but the towering peaks "
          "of the Crystal Reaches rise over the eastern horizon.");
  SetItems( ([ 
    ({ "hill", "hills" }) : "The hills of the Shire make for excellent "
                            "farming.",
    ({ "church", "temple", "building"}) : 
            "A feeling of welcome beckons from the doors of the temple.",
    ({ "peak", "peaks", "mountain", "reaches" }) : "The Crystal Reaches "
            "are the longest and most majestic of the mountain ranges of "
            "Kailie.",
    ({ "intersection" }) : "The intersection to the west connects the "
                           "road to the southern gate.",
    ]) );
  SetInventory( ([ 
    ]) );
  SetExits( ([
    "north" : LLORYK + "room/uh5",
    "west"  : LLORYK + "room/hb4",
     ]) );
  SetEnters( ([ 
    "building" : LLORYK + "room/church",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "small", "wooden", "eclat", }),
    "mountain" : ({ "crystal", "towering", }),
    ]) );
  SetSmell( ([
    "default" : "The smells of farm life ruin the air.",
    ]) );
  SetListen( ([
    "default" : "Heated debate and discussion can be heard inside the building.",
    ]) );
}
