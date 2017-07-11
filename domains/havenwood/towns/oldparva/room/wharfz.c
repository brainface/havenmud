#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetShort("on Parva's Wharf");
   SetLong("Parva's Wharf is a large wooden structure built over the "
           "water.  It continues to the north and south.  To the "
           "east are the floating docks that most boats hook "
           "up to.  To the west is a path.");
   SetItems( ([
                ({ "Parvas Wharf","wharf","structure" }) :
                   (: GetLong :),
                ({ "green murky ocean","ocean","water" }) :
                   "The green murky water to the east makes up "
                   "the ocean.",
                ({ "floating docks","docks","dock" }) :
                   "The floating docks to the east are not "
                   "accessible from here, but to the north of "
                   "here.  Boat owners dock down there.",
                ({ "Parva path","path" }) :
                   "The path goes off to the west.  Buildings "
                   "lines both sides of it.",
                ({ "ramshackle buildings","buildings","building" }) :
                   "The buildings to the west are ready to fall "
                   "apart.",
           ]) );
   SetItemAdjectives( ([
                         "path" : ({ "parva" }),
                         "wharf" : ({ "Parva","Parvas","large",
                                      "wooden" }),
                         "ocean" : ({ "green","murky" }),
                         "buildings" : ({ "ramshackle" }),
                         "docks" : ({ "foating" }),
                    ]) );
   SetListen( ([
                 "default" : "Sailor's curses and the ocean waves "
                    "fill the air with sound.",
            ]) );
   SetSmell( ([
                "default" : "Fish and rotting seaweed "
                   "odors rise up from the water.",
                "ocean" : "The ocean smells salty and fishy.",
           ]) );
   SetExits( ([
                "north" : P_ROOM + "/wharfy",
                "south" : P_ROOM + "/wharf0",
                "west"  : P_ROOM + "/path4",
           ]) );
}
