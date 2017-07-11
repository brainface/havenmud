#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetShort("in a main chamber.");
    SetLong("This is the southwest part of a large common chamber.  "
            "There is rubbish strewn about as well as the occasional "
            "bone.  There are mats set up for bedding here, as well as "
            "a now extinguished firepit in the middle.  The chamber "
            "continues off to the north, northeast and east.  The "
            "chamber is of the same roughly hewn stone as the entrance.  "
            "A passage leads off to the southwest.");
   SetItems( ([
     ({"chamber", "common chamber", "room", "entrance"}) :
       "This is the southwest part of a common chamber.  This chamber is "
       "about sixty five feet by sixty five feet and is composed of a wet "
       "grey stone.",
     "passage" :
       "The passage is about ten feet across and leads off to the "
       "southwest.",
     ({"rubbish", "garbage", "floor"}) :
       "There is miscellaneous and worthless garbage scattered about "
       "the floor, the occasional small bone is there to.",
     ({"bone", "leg bone"}) :
       "There is a leg bone here.",
     ({"extinguished firepit", "firepit", "middle", "ashes"}) :
       "The firepit is about five feet across, it is cool and is composed "
       "of ashes.",
     ({"mats", "bedding", "mat", "straw mat", "straw mats", "beddings",
       "bed", "straw", "beds"}) :
       "There are several beds made of straw sitting on the floor.",
     ({"hewn stone", "stone", "grey stone"}) :
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
      "north" : CAVES_ROOM + "cavemc2",
      "northeast" : CAVES_ROOM + "cavemc1.c",
      "east" : CAVES_ROOM "cavemc4",
      "southwest" : CAVES_ROOM + "caveea.c",
            ]) );
    SetInventory( ([
      CAVES_NPC + "goblin2"  : 2,
      CAVES_NPC + "goblin1" : 2,
      CAVES_NPC + "rat"     : 2,
                ]) );
}
