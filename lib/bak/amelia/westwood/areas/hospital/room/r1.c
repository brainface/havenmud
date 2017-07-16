#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("in a hospital");
   SetLong("The room spreads out to the east and south, filled with "
           "rows upon rows of clean white beds with clean white "
           "tables and clean white cabinets surrounding them.  "
           "Between the rows, there is plenty of space to walk and "
           "stand around and talk to patients, and plenty of "
           "room for nurses to talk to their loved ones, too.  In "
           "the west wall is a plain door.");
   SetItems( ([
                ({ "eclat hospital","room","hospital" }) :
                   (: GetLong :),
                ({ "rows of clean white beds","row","rows","beds",
                   "bed" }) :
                   "The beds are neatly made, and look to be firm "
                   "but rather comfortable.  They are arranged in "
                   "simple rows with small tables between them.  "
                   "Some also have the clean white cabinets between them, "
                   "and some cabinets are above the beds or under them "
                   "too.",
                ({ "small white tables","tables","table" }) :
                   "There is one table for each bed, and they are "
                   "all kept clean and neat so the nurses and patients "
                   "can both use them.  A few have little knobs on " 
                   "them that look like handles, so there must be "
                   "more stuff inside those drawers, too.",
                ({ "little white knobs","knobs","knob","drawers",
                   "drawer","handle","handles" }) :
                   "A few of the tables, about one in every three, "
                   "has a thicker top and in the middle, on the side "
                   "facing forward, there is a little white knob.  "
                   "None of them are open, however, so it could just "
                   "be decoration.",
                ({ "small white cabinets","cabinets","cabinet" }) :
                   "The cabinets are set around in various parts of "
                   "the room.  Many are above tables or beds, attached "
                   "up on the walls but within the reach of a muezzin.  "
                   "Others are under the beds, carefully tucked away "
                   "in places where they won't bother anyone, and still "
                   "others are between the beds, down on the floor.",
                ({ "clean white walls","walls","wall","floor","ceiling" }) :
                   "The walls are clean and white, just like the floor "
                   "and the ceiling.  People must constantly clean "
                   "to keep it so nice and pristine.  Cabinets are "
                   "attached to the wall, reaching up to the ceiling "
                   "in some cases.  The only walls here are to the "
                   "north and west, and the one to the west has a "
                   "door in it.",
           ]) );
   SetItemAdjectives( ([
                         "rows of clean white beds" : ({ "rows of",
                            "row of","clean","white","neat","pristine" }),
                         "small white cabinets" : ({ "clean","white",
                                                     "neat","pristine" }),
                         "white tables" : ({ "small","white","neat",
                                             "clean pristine" }),
                         "little white knobs" : ({ "little","white" }),
                         "clean white walls" : ({ "clean","white",
                                                  "pristine","neat" }),
                    ]) );
   SetListen( ([
                 "default" : "Some groaning noises of pain come from "
                    "the hospital rooms nearby.",
            ]) );
   SetSmell( ([
                "default" : "Though the rooms are kept so neat and "
                   "clean, some odd smells of death linger.",
           ]) );
   SetExits( ([
                "east"  : H_ROOM + "r2",
                "south" : H_ROOM + "r3",
                "out"  : H_ROOM + "cemet",
           ]) );
   SetDoor("out",H_ROOM + "door");
   SetInventory( ([
                    H_NPC + "patient" : 2+random(3),
                    H_NPC + "doc_a"   : 1,
               ]) );
}
