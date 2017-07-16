#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetShort("on Parva's Wharf");
   SetLong("Parva's Wharf is dirty and smelly, but appears to "
           "be sturdy overall.  In comparison to the buildings of "
           "Parva, it is very well-built, and was obviously made "
           "to last.  One of the few exceptions to the general "
           "state of buildings is directly west of here.  It " 
           "appears to be enterable from this side.  "
           "The ocean spans out to the east.  The wharf continues "
           "to the north and south.");
   SetItems( ([
                ({ "Parvas Wharf","wharf" }) :
                   (: GetLong :),
                ({ "ramshackle buildings","buildings","building" }) :
                   "The buildings are all shoddy around Parva.  "
                   "They were originally temporary structures, " 
                   "but since most of the life of the citizens "
                   "is spent working on the sea, they've ignored "
                   "their land dwellings.  The building to the west "
                   "is fairly well built, however.  It looks like "
                   "a temple of some sort.",
                ({ "Eclatish temple","temple" }) :
                   "The temple to the west is an Eclatish temple.  "
                   "It can be entered from this side.",
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
                         "temple" : ({ "eclatish" }),
                    ]) );
   SetListen( ([
                 "default" : "The ocean roars loudy.",
            ]) );
   SetSmell( ([
                "default" : "A salty wind brings all the  "
                   "disgusting smells of the ocean and harbor "
                   "to the wharf.",
           ]) );
   SetExits( ([
                "north" : P_ROOM + "/wharfz",
                "south" : P_ROOM + "/wharf1",
           ]) );
   SetEnters( ([
                 "building" : PS_ROOM + "/eclat",
                 "temple" : PS_ROOM + "/eclat",
            ]) );
   SetInventory( ([
                     P_NPC + "/cit" : 2,
               ]) );
}
