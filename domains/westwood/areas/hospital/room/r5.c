#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("in a hospital");
   SetLong("The hospital walls are white, and so is the ceiling and "
           "floor.  All are perfectly clean, as well as the beds and "
           "tables around the room.  To one side is a ramp that heads "
           "down into a dark area of the hospital, while the hospital "
           "room itself continues to the west.  To the north is an "
           "opening that leads out of this part of the hospital.");
   SetItems( ([
                ({ "eclat hospital","hospital","room" }) :
                   (: GetLong :),
                ({ "hospital walls","walls","wall","ceiling","floor" }) :
                   "The walls are clean and white, and to the north, "
                   "there is an opening out of this part of the "
                   "hospital.  The rows of beds with small tables "
                   "stand in front of the walls, as well as a number of "
                   "white cabinets that hang onto them.",
                ({ "rows of white beds","rows","row","bed","beds" }) :
                   "The beds are organized in neat rows that fit the "
                   "most beds into the room while still leaving plenty "
                   "of space for other items, like the tables that are "
                   "stuck between them.  They are all perfectly clean.",
                ({ "small tables","tables","table" }) :
                   "There is one table for each of the beds, and it is "
                   "pushed right up against its assigned bed.  They are "
                   "all kept neat and clean, with room on them for "
                   "the patients and the doctors and nurses.",
                ({ "north opening","opening","doorway","door" }) :
                   "The opening to the north is just a doorway that "
                   "doesn't have a door.  It leads out of this part of "
                   "the hospital.",
                ({ "gentle ramp","ramp" }) :
                   "The ramp leads down into the earth itself to provide "
                   "a dark area for patients that are used to living in "
                   "conditions without light, like the nosferatu.  The "
                   "slope of the ramp is gentle, allowing easy access to "
                   "the area below.",
                ({ "dark area","area" }) :
                   "A gentle ramp leads down into the earth, where a "
                   "dark area exists in the hospital.  It is for all "
                   "the patients who are not used to living in such "
                   "bright conditions as exist out here, or ones whose "
                   "eyes are tender as a result of whatever accident "
                   "occured and would be damaged by the exposure to "
                   "light.",
           ]) );
   SetItemAdjectives( ([
                         "walls" : ({ "hospital","clean","white",
                                      "perfectly" }),
                         "beds" : ({ "rows of","row of","clean","white",
                                     "organized","neat","perfectly" }),
                         "tables" : ({ "small","neat","clean","white" }),
                         "opening" : ({ "north" }),
                         "ramp" : ({ "gentle","dark" }),
                    ]) );
   SetSmell( ([
                "default" : "Cleaning smells fill the room.",
           ]) );
   SetListen( ([
                 "default" : "The groans of the sick and injured "
                    "come from all around.",
            ]) );
   SetExits( ([
                "north" : H_ROOM + "waiting",
                "west"  : H_ROOM + "r4",
                "down"  : H_ROOM + "down1",
           ]) );
   SetInventory( ([
                    H_NPC + "patient" : 3,
                    H_NPC + "doc_a" : 1,
               ]) );
}
