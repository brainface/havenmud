#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetClimate("indoors");
     SetShort("small stairwell");
      SetLong("The small room serves mainly as the stairwell to the upper "
        "stories of the keep. The floor and walls are made of a nondescript "
        "stone, and nothing appears as rundown as in the main entrance. A "
        "rickity old stool lies in the corner.");
     SetItems( ([
        ({ "entrance", "main entrance"}) :
                 "The main entrance is to the west.",
         ({ "stool"}):
                 "The rickety old stool looks to be very, very old.",
      ({"stones", "floor" }) : "The stone floor, while clean, is bare of any "
      "remarkable characteristics.",
      ({"wall", "walls"}) : "The walls are of a rough, imported stone.",
           ]) );
     SetItemAdjectives( ([
        "stool" : ({"rickety","old"}),
         "wall" : ({"rough","stone"}),
         ]) );
    SetSmell( ([
                "default" : "The cloying smell of wet stone and " 
                       "earth is detectable. "
                       ]) );
    SetListen( ([
                "default" :  "Voices can be heard echoing above. "
             ]) );
     SetExits( ([
          "up" : AVERATH_CITY + "keep3",
          "west" : AVERATH_CITY + "keep1",
                   ]) );
      SetInventory( ([ AVERATH_NPC + "fighter_leader" : 1 ]) );
}
