#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetShort("in a main chamber.");
    SetLong("This is the southeast part of a large common chamber.  "
            "There is rubbish strewn about as well as the occasional "
            "bone.  There are mats set up for bedding here, as well as "
            "a now extinguished firepit in the middle.  The chamber "
            "continues off to the north, northwest and west.  The "
            "chamber is of the same roughly hewn stone as the entrance.  "
            "A passage leads off to the southeast.");
   SetItems( ([
     ({"chamber", "common chamber", "room", "entrance"}) :
       "This is the southeast part of a common chamber.  This chamber is "
       "about sixty five feet by sixty five feet and is composed of a "
       "wet grey stone.",
     "passage" :
       "The passage is about ten feet across and leads off to the "
       "southeast.",
     ({"rubbish", "garbage", "floor"}) :
       "There is miscellaneous and worthless garbage scattered about "
       "the floor, the occasional small bone is there to.",
     ({"small bone", "bone"}) :
       "There is a small bone here.",
     ({"extinguished firepit", "firepit", "middle", "ashes"}) :
       "The firepit is about five feet across, it is cool and is composed "
       "of ashes.",
     ({"mats", "bedding", "mat", "straw mats", "straw mat", "beddings",
       "beds", "bed", "straw"}) :
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
        "The frequent drip of water can be heard.  Running water "
        "can be heard off to the southeast.",
             ]) );
    SetExits( ([
      "north" : CAVES_ROOM + "cavemc1",
      "northwest" : CAVES_ROOM + "cavemc2",
      "west" : CAVES_ROOM "cavemc3",
      "southeast" : CAVES_ROOM + "cavestream.c",
            ]) );
    SetInventory( ([
      CAVES_NPC + "goblin1" : 1,
      CAVES_NPC + "goblin2" : 2,
      CAVES_NPC + "rat"     : 2,
                ]) );
}
