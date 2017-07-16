// Amelia@Haven
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
           "plain path.  To the west, the path continues, and "
           "buildings are on either side.  Some trash rots on "
           "the edges of the path.  The building south of "
           "here looks rather fancy.  The smithy on the north "
           "side of the road is just as ramshackle as the other "
           "buildings.");
   SetItems( ([
                ({ "Parva smithy","smithy" }) :
                   "The smithy is ready to fall apart, but "
                   "can be entered from here.",
                ({ "rotting trash","trash","peel","peels",
                   "creatures","creature","plants","plant" }) :
                   "Trash rots on the edges of the path.  It "
                   "is compromised of various sea creatures and "
                   "plants, as well as discarded rags and "
                   "fruit peels.",
                ({ "expansive ocean","ocean","water" }) :
                   "The water is murky and green, but it "
                   "stretches out for many miles.",
                ({ "east wharf","wharf","dock","docks" }) :
                   "The wharf is to the east.  It is a "
                   "big dock that is sturdy and held in place "
                   "against the tides.  The docks that most "
                   "boats go to are smaller and float on the "
                   "water.",
                ({ "Parva path","path","parva" }) :
                   (: GetLong :),
                ({ "ramshackle buildings","buildings","building" }) :
                   "Buildings fill Parva.  They are all temporary "
                   "in design, and ready to fall apart, except "
                   "one just south of here, which is, unfortunately, "
                   "not enterable from this side.",
           ]) );
   SetItemAdjectives( ([
                         "trash" : ({ "sea","discarded","fruit",
                                      "rotting" }),
                         "ocean" : ({ "expansive" }),
                         "wharf" : ({ "east" }),
                         "smithy" : ({ "parva","parvas" }),
                         "path" : ({ "parva","plain" }),
                         "buildings" : ({ "ramshackle" }), 
                    ]) );
   SetListen( ([
                 "default" : "Cursing sailors yell against the "
                    "crashing waves to the east.",
            ]) );
   SetSmell( ([
                "default" : "The smells of rotting fish and salt "
                    "reach the road.", 
           ]) );
   SetExits( ([
                "east" : P_ROOM + "/wharfz",
                "west" : P_ROOM + "/path5",
           ]) );
   SetEnters( ([
                 "smithy" : P_ROOM + "/smithy",
            ]) );
   SetInventory( ([
                     P_NPC + "/cit" : 2,
               ]) );
}
