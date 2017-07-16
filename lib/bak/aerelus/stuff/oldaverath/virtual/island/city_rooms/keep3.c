#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetClimate("temperate");
     SetShort("main hall of the second floor");
      SetLong("The small hallway is damp and cold, making staying here "
          "for more than a few moments quite miserable. The floor and walls "
          "are made from the same nondescript stone as the room below. "
          "A staircase leads down, while to the north and east further rooms "
      "can be seen.");
     SetItems( ([
        ({ "hallway", "small hallway"}) :
                 "This small hallway intersects the second floor..",
         ({ "staircase"}):
                 "The curved staircase leads down to the first floor.",
      ({"stones", "floor" }) : "The stone floor, while clean, is bare of any "
       "remarkable characteristics.",
      ({"wall", "walls"}) : "The walls are of a rough, imported stone.",
           ]) );
    SetSmell( ([
                "default" : "The cloying smell of wet stone and " 
                       "earth is detectable. "
                       ]) );
    SetListen( ([
                "default" :  "The hallway is eerily silent. "
             ]) );
     SetExits( ([
          "east" : AVERATH_CITY + "keep4",
          "down" : AVERATH_CITY + "keep2",
          "north" : AVERATH_CITY + "keep5",
                   ]) );
}
