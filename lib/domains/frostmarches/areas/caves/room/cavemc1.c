#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetShort("in a main chamber.");
    SetLong("This is the northeast part of a large common chamber.  "
            "There is rubbish strewn about as well as the occasional "
            "bone.  There are mats set up for bedding here, as well as "
            "a now extinguished firepit in the middle.  The chamber "
            "continues off to the south, southwest and west.  The "
            "chamber is of the same roughly hewn stone as the entrance.");
   SetItems( ([
     ({"chamber", "common chamber", "room", "entrance"}) :
       "This is the northeast part of a common chamber.  This chamber is "
       "about sixty five feet by sixty five feet and is composed of a wet "
       "grey stone.",
     ({"rubbish", "garbage", "floor"}) :
       "There is miscellaneous and worthless garbage scattered about "
       "the floor, the occasional small bone is there to.",
         ({"bone", "small bone", "small leg bone"}) :
           "There is a small leg bone here.",
     ({"extinguished firepit", "firepit", "middle", "ashes"}) :
       "The firepit is about five feet across, it is cool and is composed "
       "of ashes.",
     ({"mats", "bedding", "mat", "straw mat", "straw mats", "bed",
       "beds", "mat"}) :
       "There are several beds made of straw sitting on the floor.",
     ({"hewn stone", "stone"}) :
       "This grey stone is of the type easily worn by chisel or by "
       "water.",
          ]) );
    SetSmell( ([
      "default" :
        "This room smells of garbage.",
            ]) );
    SetListen( ([
      "default" :
        "The frequent drip of water can be heard.",
             ]) );
    SetExits( ([
      "south" : CAVES_ROOM + "cavemc4",
      "southwest" : CAVES_ROOM + "cavemc3",
      "west" : CAVES_ROOM "cavemc2",
            ]) );
    SetInventory( ([
      CAVES_NPC + "goblin1" : 2,
      CAVES_NPC + "goblin2" : 2,
      CAVES_NPC + "rat" : 3,
                ]) );
}
