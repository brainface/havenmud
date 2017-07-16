#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetShort("in Parva");
   SetDomain("HavenWood");
   SetLong("The expansive ocean can be seen clearly from here.  "
           "The wharf and docks are east of here, along this "
           "main road.  To the west is the rest of Parva, and "
           "buildings are on either side of the road.  The "
           "building to the north looks like it is frequented "
           "often.  It is probably a place one could buy "
           "alcohol at.");
   SetItems( ([
                ({ "expansive ocean","ocean","water" }) :
                   "The water is murky and green, but it "
                   "stretches out for miles.",
                ({ "east wharf","wharf","dock","docks" }) :
                   "The wharf is to the east.  It is a "
                   "big dock that is sturdy and help in place "
                   "against the tides.  The docks that most "
                   "boats go to are smaller and float on the "
                   "water.",
                ({ "main road","road","parva" }) :
                   (: GetLong :),
                ({ "Pons Store", "store", "pons", "building" }) :
                   "Pons' Store is south of here.  One can "
                   "enter from this side.",
                 ({ "Minkins Inn", "inn", "minkins", "building" }) :
                   "Minkin's Inn is to the north.  One can "
                   "enter from here.",
/*   Commented out because were from old Parva and were messing
//   up now-present store and inn.
                ({ "ramshackle buildings","buildings","building" }) :
                   "The buildings to the north and south are "
                   "enterable from here.  They look like they "
                   "were made better than the other buildings around "
                   "here.",
*/
           ]) );
   SetItemAdjectives( ([
                         "ocean" : ({ "expansive" }),
                         "wharf" : ({ "east" }),
                         "road" : ({ "main","parva" }),
                         "store" : ({ "store of","pons","building" }),
                         "inn" : ({ "minkins","minkin","inn of" }),
                         "buildings" : ({ "ramshackle" }), 
                    ]) );
   SetListen( ([
                 "default" : "A lot of commotion comes from the "
                    "east, as well as the sound of the ocean waves.",
            ]) );
   SetSmell( ([
                "default" : "The smells of fish and the ocean "
                    "reach the road.", 
           ]) );
   SetExits( ([
                "east" : P_ROOM + "/wharf2",
                "west" : P_ROOM + "/path2",
           ]) );
   SetEnters( ([
                 "inn" : P_ROOM + "/inn",
                 "store" : P_ROOM + "/store",
            ]) );
   SetInventory( ([
                    P_OBJ + "/sign3" : 1,
                     P_NPC + "/cit" : 1,
                    P_NPC + "/rogue_leader" : 1,
               ]) );
}
