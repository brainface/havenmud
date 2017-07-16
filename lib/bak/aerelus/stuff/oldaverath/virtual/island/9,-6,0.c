// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("near a crashed ship");
   SetLong("Rammed against the sea cliffs is an old ship, with barnacles "
           "growing on its rotting boards.  The ocean licks against the "
           "bow, lapping at the rocky shore.  The beach itself continues "
           "to the north and west.");
   SetItems( ([
                ({ "crashed ship","ship","hole" }) :
                   "The ship is slowly falling to pieces.  A large hole has "
                   "formed on the side.",
                ({ "rotting boards","board","boards","barnacles","barnacle" }) :
                   "The boards are slowly falling into little pieces.  Small white "
                   "barnacles are growing on most of the boards, especially the ones "
                   "near the bottom.",
                ({ "ocean" }) :
                   "The ocean sends waves after waves towards the shore.",
                ({ "rocky shore","shore","coast","beach" }) : (: GetLong :),
           ]) );
   SetItemAdjectives( ([
                         "ship" : ({ "old","large","crashed" }),
                         "boards" : ({ "rotting" }),
                    ]) );
   SetSmell( ([
                "default" : "Salty wafts of air arise from the ocean.",
           ]) );
   SetListen( ([
                 "default" : "The ocean waves knock against the side of the ship.",
            ]) );
   SetExits( ([
                "west" : AVERATH_ISLAND + "8,-6,0",
                "north" : AVERATH_ISLAND + "9,-5,0",
                "east"  : INNERSEA_VIRTUAL "ocean/10,-111",
                "south" : INNERSEA_VIRTUAL "ocean/9,-112",
           ]) );
   SetEnters( ([
                 "ship" : FOREST_ROOMS + "ship",
            ]) );
   SetInventory( ([
                    FOREST_NPC + "otter" : 2,
                    FOREST_NPC + "sailorghost" : 3,
               ]) );
}
