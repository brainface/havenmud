#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("Havenwood");
   SetShort("on Parva's Wharf");
   SetLong("The water spread out in front of the wharf, to the east "
           "where the floating docks are.  There is a building to "
           "the west and the wharf continues to the north and south.  "
           "The water looks rather dirty here.  A steep ramp "
           "leads down to the docks.");
   SetItems( ([
                ({ "Parvas Wharf","wharf" }) :
                   (: GetLong :),
                ({ "floating docks","docks","dock" }) :
                   "The docks float serenly on the wave-filled "
                   "ocean.",
                ({ "dirty water","water","ocean" }) :
                   "The ocean is a simple green color, but "
                   "it looks dirty.",
                ({ "ramshackle building","building" }) :
                   "The building to the west, and indeed all of "
                   "the buildings in Parva, are fairly shoddy "
                   "and temporary.  The one to the west is not "
                   "as bad as most, but still could use some "
                   "repairs and rebuilding.",
                ({ "Minkins Inn","inn" }) :
                   "Minkin's Inn is to the west.  One can "
                   "enter from this side by going west.",
                ({ "steep ramp","ramp" }) :
                   "The ramp leads down to the docks.  A number "
                   "of grooves on one side of it allow one "
                   "better purchase on the steep slope.",
           ]) );
   SetItemAdjectives( ([
                         "wharf" : ({ "parvas","parva" }),
                         "docks" : ({ "floating" }),
                         "water" : ({ "dirty","wave-filled" }),
                         "building" : ({ "ramshackle" }),
                         "inn" : ({ "inn of","minkins","minkin" }),
                         "ramp" : ({ "steep" }),
                    ]) );
   SetListen( ([
                 "default" : "The water crashes loudly against "
                    "the shore.",
            ]) );
   SetSmell( ([
                "default" : "The smells of the ocean fill the "
                   "air.",
           ]) );
   SetExits( ([
                "down"  : P_ROOM + "/docks1",
                "south" : P_ROOM + "/wharf2",
                "north" : P_ROOM + "/wharf0",
           ]) );
  SetEnters( ([
    "inn" : P_ROOM + "/inn",
  ]) );
   SetInventory( ([
                    P_OBJ + "/sign_g" : 1,
                    P_NPC + "/sailor_leader" : 1,
               ]) );
}
