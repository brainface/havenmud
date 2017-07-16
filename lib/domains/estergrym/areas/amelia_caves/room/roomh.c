// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("the trickling stream");
   SetLong("A small, cold stream trickles into the tunnels here by way "
           "of an opening in the western wall.  Slick shapes wind around "
           "beneath the surface, indistinct in the dark, murky waters.  "
           "The tunnel goes to the northeast to more dry areas, and "
           "downward by the banks of the stream.");
   SetItems( ([
                ({ "stream","small stream","cold stream" }) :
                   "The stream is icy-cold around where it slides its "
                   "way into the room through an opening in the western "
                   "wall of this small cavern.  Beneath its dark and "
                   "murky surface, fish-like shapes dance downstream.",
                ({ "stream's water","water" }) :
                   "The water is cold and icy.",
                ({ "western wall","wall" }) :
                   "The wall has an opening "
                   "in it that a stream flows through.",
                ({ "opening of western wall","opening" }) :
                   "The opening is roughly circular in shape, "
                   "with a stream flowing through it.",
                ({ "slick shapes","fish","shapes","shape","slick shape" }) :
                   "The shapes are little trout, with strange bumps "
                   "where their eyes should be.",
                ({ "strange bumps","eyes","strange bump","eye" }) :
                   "The little bumps are the remenants of eyes in these "
                   "fish, eyes which are no longer necessary due to the "
                   "darkness here in the caves.",
                ({ "river surface","surface" }) :
                   "The surface of the river reflects its "
                   "surroundings.",
           ]) );
   SetListen( ([
                 "default" : "The water rushes by noisily."
            ]) );
   SetExits( ([
                "down" : C_ROOM + "roomm",
                "northeast" : C_ROOM + "roomb",
           ]) );
   SetInventory( ([
                    C_NPC + "dogfish" : 2,
                    C_NPC + "trout" : 1,
                    C_NPC + "catfish" : 1,
              ]) );
}
