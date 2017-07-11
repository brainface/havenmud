#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("in a hospital");
   SetLong("The hospital walls are clean and white, and the beds are "
           "set in neat, organized rows with small tables and cabinets "
           "between and around them.  Where the walls meet the ceiling, "
           "little golden balls are been hung to shed light on the "
           "surroundings.  The room continues to the north and the "
           "south, unfettered by walls.");
   SetItems( ([
                ({ "eclat hospital","hospital","room" }) :
                   (: GetLong :),
                ({ "hospital walls","wall","walls","floor","ceiling" }) :
                   "The walls of the hospital shine, all polished "
                   "clean.  Up where the walls and the ceiling "
                   "meet, little golden balls hang to light up the "
                   "room with a comforting glow.  The floor is "
                   "just like the walls and the ceiling, only it "
                   "is mostly covered by the tables and cabinets and "
                   "beds, though some of them block view of the walls, "
                   "too.",
                ({ "neat organized rows of beds","beds","bed","rows",
                   "row" }) :
                   "The beds are set up in rows, carefully organized to "
                   "maximize space.  Between the beds are small tables "
                   "and some cabinets, which are also suspended above "
                   "the beds.  The beds themselves are clean and neat, "
                   "prepared for the sick.",
                ({ "little golden balls","ball","ball","gold" }) :
                   "The balls are hung up at the point where the "
                   "ceiling and the wall meet, and are basically "
                   "out of the way where they will bother no one.  "
                   "They shine prettily and light the room.",
           ]) );
   SetItemAdjectives( ([
                         "hospital walls" : ({ "clean","white","hospital" }),
                         "neat organized rows of beds" : ({ "neat",
                             "organized","clean","white","pristine",
                             "rows of","row of" }),
                         "little golden balls" : ({ "little","golden" }),
                    ]) );
   SetListen( ([
                 "default" : "Patients nearby groan and cry for "
                    "nurses.",
            ]) );
   SetSmell( ([
                "default" : "The constant cleaning of the hospital "
                   "cannot mask the sense of pain and death in its "
                   "smells.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "r1",
                "south" : H_ROOM + "r4",
           ]) );
   SetInventory( ([
                    H_NPC + "doc_d" : 1,
                    H_NPC + "patientg" : random(2),
                    H_NPC + "patient" : 3,
                    H_NPC + "doc_a" : 1,
               ]) );
}
