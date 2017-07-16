#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   SetDomain("WestWood");
   SetAmbientLight(45);
   SetClimate("indoors");
   SetShort("the Soleil Music Store");
   SetLong("Various instruments sit on the shelves, "
           "arranged carefully so that they won't "
           "fall or be damaged by misplaced movements.  "
           "An archway leads into the music hall to "
           "the west.  One can exit out as well.");
   SetItems( ([
                ({ "Soleil Music Store","store",
                   "soleil" }) : (: GetLong :),
                ({ "various instruments","instruments",
                   "instrument","shelf","shelves" }) :
                   "The instruments are set out for "
                   "storage and display both.  The "
                   "storekeeper will glady show "
                   "them in greater detail to any "
                   "interested customer.",
                ({ "west archway","archway","arch",
                   "music hall","hall" }) :
	"Shelves are set out to hold various "
	"instruments. There are also areas in "
	"the room designed for practice. "
	"An archway leads into the music store to "
	"the west. One can exit out as well.",
           ]) );
   SetItemAdjectives( ([
                         "store" : ({ "soleil","music" }),
                         "arch" : ({ "west" }),
                    ]) );
   SetSmell( ([
                "default" : "The smells of paper and wood "
                   "and forest fill the room.",
           ]) );
   SetListen( ([
                 "default" : "Musical sounds fill the air.",
            ]) );
   SetExits( ([
                "out"  : S_ROOM + "up3",
                "west" : S_ROOM + "hall",
           ]) );
   SetInventory( ([
                    S_NPC + "musicvend" : 1,
               ]) );
}
