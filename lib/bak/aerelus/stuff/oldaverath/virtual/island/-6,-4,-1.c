/*  A Bears Den  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("an animal's den");
  SetLong("This, quite obviously, is the den of some bears.  Scattered "
          "around the cave are the bones of some unrecognizable wild "
          "animals, as well as some fish parts littering the room.  Blood "
          "seems to stain the ground red here.  Up on the ceiling water "
          "trickles in near the back of the cave.");
  SetListen( ([ 
    "default"  :  "Dripping water plunks from the ceiling.",
    ]) );
  SetExits( ([ 
    "west"  :  ROOMLV1 + "-7,-4,-1",
    ]) );
  SetItems( ([ 
    ({ "den", "cave" })  :  (: GetLong :),
    ({ "bones", "bone", "fish parts", "parts" })  :
       "Upon closer inspection you also notice a few human, and elven bones "
       "mixed in with the bones of animals and fish.",
    ({ "crimson blood", "blood", "ground" })  :
       "On the ground you can see the blood from the bear's victims has "
       "stained the ground that you are standing on a nice crimson red.",
    ({ "ceiling", "water" })  :
       "In the back of the cave water is dripping from the ceiling in "
       "multiple places, leaving large puddles of water on the ground.",
    ({ "puddles of water", "puddles", "water puddles" })  :
       "The water that trickles into the cave comes to rest in puddles in the "
       "back of the cave.",
    ]) );
  SetSmell( ([
    "default"  :  "The smell of blood and wet fur is here.",
    "blood"    :  "The blood smells fresh, probably from the last person "
                  "to wander in.",
    ]) );
  SetInventory( ([ NPCS + "bear" : 1,
                   NPCS + "cubf" : 1,
                   NPCS + "cubm" : 1,
    ]) );
}
