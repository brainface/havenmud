#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetShort("on Parva's Wharf");
   SetLong("Parva's Wharf is dirty and smelly, but appears to "
           "be sturdy overall.  In comparison to the buildings of "
           "Parva, it is very well-built, and was obviously made "
           "to last.  One such terrible building is just west of "
           "here, but there are no entrances on this side.  "
           "The ocean spans out to the east.  The wharf continues "
           "to the north.");
   SetItems( ([
                ({ "Parvas Wharf","wharf" }) :
                   (: GetLong :),
                ({ "ramshackle buildings","buildings","building" }) :
                   "The buildings are all shoddy around Parva.  "
                   "They were originally temporary structures, " 
                   "but since most of the life of the citizens "
                   "is spent working on the sea, they've ignored "
                   "their land dwellings.",
                ({ "expansive ocean","ocean","water" }) :
                   "The ocean is smelly and dirty around the "
                   "wharf, with the trash that the humans here "
                   "dump into it, but farther out, it looks "
                   "pure and beautiful.",
           ]) );
   SetItemAdjectives( ([
                         "wharf" : ({ "parva","parvas","dirty",
                                      "smelly","well-built" }),
                         "buildings" : ({ "ramshackle","terrible" }),
                         "ocean" : ({ "expansive" }),
                    ]) );
   SetListen( ([
                 "default" : "The ocean roars.",
            ]) );
   SetSmell( ([
                "default" : "A salty wind brings all the joyous and "
                   "disgusting smells of the ocean and harbor "
                   "to the wharf.",
           ]) );
   SetExits( ([
                "north" : P_ROOM + "/wharf2",
           ]) );
   SetInventory( ([
                    P_NPC + "/hunter" : 1,
               ]) );
}
