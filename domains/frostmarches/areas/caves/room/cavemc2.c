#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetShort("in a main chamber.");
    SetLong("This is the northwest part of a large common chamber.  "
            "There is rubbish strewn about as well as the occasional "
            "bone.  There are mats set up for bedding here, as well as "
            "a now extinguished firepit in the middle.  The chamber "
            "continues off to the south, southeast and east.  The "
            "chamber is of the same roughly hewn stone as the entrance. "
            "A painting is on the north wall.");
   SetItems( ([
     ({"painting", "north wall", "painting of ogre"}) :
       "There is a painting of an ogre with goblins running from it on the "
       "north wall",
     ({"chamber", "common chamber", "room", "entrance"}) :
       "This is the northwest part of a common chamber.  This chamber is "
       "about sixty five feet by sixty five feet and is composed of a wet "
       "grey stone.",
     ({"rubbish", "garbage", "floor"}) :
       "There is miscellaneous and worthless garbage scattered about "
       "the floor, the occasional small bone is there to.",
         ({"bone", "small bone", "piece of bone", "small piece of bone"}) :
           "There is a small piece of bone here.",
     ({"extinguished firepit", "firepit", "middle", "ashes"}) :
       "The firepit is about five feet across, it is cool and is composed "
       "of ashes.",
     ({"mats", "bedding", "mat", "straw mats", "straw mat", "beddings",
       "beds", "bed", "straw"}) :
       "There are several beds made of straw sitting on the floor.  "
       "They are crudely constructed and do not look very comfortable.",
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
      "south" : CAVES_ROOM + "cavemc3",
      "southeast" : CAVES_ROOM + "cavemc4",
      "east" : CAVES_ROOM "cavemc1",
            ]) );
    SetInventory( ([
      CAVES_NPC + "goblin1" : 1,
      CAVES_NPC + "goblin2" : 2,
      CAVES_NPC + "rat"     : 2,
                ]) );
}
