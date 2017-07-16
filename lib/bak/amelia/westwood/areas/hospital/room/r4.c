#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("in a hospital");
   SetLong("The walls turn here, forming a corner in the hospital with "
           "open passages to the north and east which lead into "
           "hospital rooms that look basically identical to this "
           "one:  Clean white beds in neat, ordered rows fill most "
           "of the available space; white cabinets and small tables "
           "are nudges between the beds and more cabinets are "
           "on the walls or under the beds.  There are no windows "
           "and no doors here.");
   SetItems( ([
                ({ "eclat hospital","hospital","room","corner" }) :
                   (: GetLong :),
                ({ "white walls","walls","wall" }) :
                   "The walls are clean and white, turning to the north "
                   "and east alongside the passageways.  Various "
                   "items sit in front of them, like the beds and "
                   "tables, and some cabinets are mounted on the walls "
                   "themselves.",
                ({ "white cabinets","cabinets","cabinet" }) :
                   "The cabinets are stuck all around, but mostly in "
                   "secure out-of-the-way areas.  Some are on the wall "
                   "and others under beds and some between them.  They "
                   "are all clean and white.",
                ({ "white beds","bed","beds","rows","row" }) :
                   "The beds are in neat rows set up to maximize space "
                   "while retaining comfortable areas for movement.  "
                   "They are all clean and white, some set up on "
                   "cabinets, and there are tables for each bed.",
                ({ "small tables","tables","table" }) :
                   "The tables are set up with space for both a "
                   "patient's and a doctor's things.  There is "
                   "one for each bed, and they are set up between them.  "
                   "They are all white and neat.",
           ]) );
   SetItemAdjectives( ([
                         "white walls"    : ({ "white","clean" }),
                         "white cabinets" : ({ "white","clean" }),
                         "white beds"     : ({ "white","clean","neat",
                                               "rows of","row of" }),
                         "small tables"   : ({ "small","white","clean",
                                               "neat" }),
                    ]) );
   SetListen( ([
                 "default" : "Groans come from nearby areas.",
            ]) );
   SetSmell( ([
                "default" : "Everything smells immaculately clean.",
           ]) );
   SetExits( ([
                "east"  : H_ROOM + "r5",
                "north" : H_ROOM + "r3",
           ]) );
   SetInventory( ([
                    H_NPC + "patient" : 2,
                    H_NPC + "doc_a" : 1,
               ]) );
}
