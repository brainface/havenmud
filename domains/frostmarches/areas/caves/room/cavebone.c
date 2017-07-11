#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM ;

static void create() {
    room::create();
    SetAmbientLight(5);
    SetClimate("underground");
    SetShort("a pile of bones");
    SetLong("This chamber is filled with water about a half foot deep.  "
            "There is a large pile of bones sitting in the middle of "
            "this room.  The chamber is about twenty feet across by "
            "twenty "
            "feet long, and is composed of the same roughly hewn, grey "
            "stone as the rest of the cave.  Work on this room look like "
            "it was abondoned when it started filling up with water.");
    SetItems( ([
      ({"pile of bones", "pile", "bones", "bone", "pile of bone",
        "large pile", "large pile of bones"}) :
        "This is a large pile of bones consisting of a hundred or "
        "so creatures.  They are in no particular order or of any "
        "particular race.  The bones are not all old either, many "
        "of them have small bits of flesh clinging to them.",
     ({"filth ridden water", "putrid water", "putrid filth ridden water",
       "water"}) :
         "There is about a half foot of putrid water in this chamber.  It "
         "apparently runs down from the cave's entrance.",
          ({"small bits of flesh", "small bit of flesh", "flesh",
            "bits", "bit", "rotting flesh", "small bit", "small bits",
            "bit of flesh", "bits of flesh"}) :
              "Something was apparently careless when it eats, there's "
              "still flesh on these bones.",
      ({"grey stone", "stone", "cave", "roughly hewn stone",
        "grey sedimentary rock", "sedimentary rock", "rock", "grey rock",
        "roughly hewn grey stone", "hewn stone", "roughly hewn stone", 
        "stone"}) :
        "This is a grey sedimentary rock that is easily worn by "
        "water or chisel.",
     ({"chamber", "room"}) :
       (: GetLong :),
            ]) );
   SetListen( ([
     "default" :
       "There are voices speaking gobyshkin coming from the north. The frequent "
       "drip of water can be heard.",
            ]) );
   SetSmell( ([
     "default" : 
       "There is an almost overwhelming stench of rotting flesh in this "
       "room.",
           ]) );
   SetExits( ([
     "north" : CAVES_ROOM + "cavew",
           ]) );
}
