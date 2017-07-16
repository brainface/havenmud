#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;

static void create() {
   ::create();
   SetDomain("HavenWood");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetTown("Parva");
   SetShort("a hospital room");
   SetLong("Open windows look out on Parva below on the north side of this "
           "hospital room.  Cabinets hold some of the necessary "
           "supplies in cabinets on the south side, and a ramp takes up "
           "much of the east side of the room, going down to the floor "
           "below.  An archway leads west into more hospital space, "
           "and cots for the patients are to the sides of the windows.");
   SetItems( ([
                ({ "hospital","room" }) : (: GetLong :),
                ({ "parva" }) : "Parva is spread out below, with its "
                   "streets and dusty buildings and the wide expanse "
                   "of ocean and forest beyond.",
                ({ "ocean" }) : "The ocean is out of the hospital and to "
                   "the east, and the windows give a wonderful view "
                   "of its green-blue waters and fishing boats and "
                   "distant islands of rock.",
                ({ "open windows","windows","window" }) :
                   "The windows are made of fairly clear glass, and "
                   "are currently open.",
                ({ "ramp" }) : "The ramp gently slopes down towards the "
                   "ground floor.",
                ({ "cots","cot" }) :
                   "Set near the windows, but not directly in front of "
                   "the chill waft coming from them, the cots are "
                   "neatly prepared for patients.",
                ({ "forest" }) : "The HavenWood is mostly south of here "
                   "and is visible through the windows.",
                ({ "fishing boats","boats","boat" }) :
                   "The boats are too distant to see in great detail, but "
                   "the fish and seafood gathered on the boats feeds "
                   "Parva well.",
                ({ "distant islands","islands","island","rock" }) :
                   "Far off, faint hints of rock protruding from the "
                   "crashing waves can be seen.",
           ]) );
   SetItemAdjectives( ([
                         "windows" : ({ "open" }) ,
                         "cabinets" : ({ "locked" }),
                         "ocean" : ({ "green","blue" }),
                         "boats" : ({ "fishing" }), 
                         "islands" : ({ "rock","distant" }),
                    ]) );
   SetSmell( ([
                "default" : "Fresh saltwater scents waft in from the ocean.",
           ]) );
   SetListen( ([
                 "default" : "The hubbub of Parva can be heard among "
                             "crashing waves and groaning patients.",
            ]) );
   SetExits( ([
                "down" : PR + "/entrance",
                "west" : PR + "/room5",
           ]) );
   SetInventory( ([
                    PN + "/doctor" : 1,
                    PO + "/cabinet" : 2,
                    PN + "/invalid" : 2,
                    PN + "/poison" : 5,
                    PN + "/patient" : 2,
               ]) );
}
