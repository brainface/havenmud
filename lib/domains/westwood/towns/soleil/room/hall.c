#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the Soleil Music Hall");
   SetLong("Shelves are set out to hold various "
           "instruments.  There are also areas in "
           "the room designed for practice.  "
           "An archway leads into the music store to "
           "the east.  One can exit out as well.");
   SetItems( ([
                ({ "Soleil Music Hall","hall",
                   "soleil" }) : (: GetLong :),
                ({ "various instruments","instruments",
                   "instrument","shelf","shelves" }) :
                   "The shelves hold all the instruments "
                   "that the bard treacher and her "
                   "students need regularly for "
                   "practice.",
                ({ "west archway","archway","arch",
                   "music store","store" }) :
          "Various instruments sit on the shelves, "
          "arranged carefully so that they won't "
         "fall or be damaged by misplaced movements. "
          "An archway leads into the music hall to "
          "the west. One can exit out as well.",
           ]) );
   SetItemAdjectives( ([
                         "hall" : ({ "soleil","music" }),
                         "arch" : ({ "east" }),
                    ]) );
   SetSmell( ([
                "default" : "The smells of paper and wood "
                   "and forest fill the room.",
           ]) );
   SetListen( ([
                 "default" : "There are wonderful acoustics in "
                    "this room.",
            ]) );
   SetExits( ([
                "out"  : S_ROOM + "up1",
                "east" : S_ROOM + "musicstore",
           ]) );
   SetInventory( ([
                    S_NPC + "bardt" : 1,
               ]) );
}
