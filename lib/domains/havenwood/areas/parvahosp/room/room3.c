#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;

static void create() {
   ::create();
   SetDomain("HavenWood");
   SetTown("Parva");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("a quiet room");
   SetLong("Storage cabinets line the wall on the west side, and cots line the "
           "remaining walls. The room stretches to the east, continuing in the "
           "lines of cots and patients. Counters displays some useful hospital "
           "items under the cabinets.");
   SetItems( ([
                ({ "quiet room","room","hospital" }) : (: GetLong :),
                ({ "walls","wall" }) :
                   "The walls are just normal wood color, never painted.",
                ({ "cots","cot","beds","bed" }) :
                   "Beds, made light and sturdy for easy mobility and practicality, "
                   "sit in organized rows on the sides of the walls, with space "
                   "open in the middle of the room for another row.",
                ({ "counters","counter","hospital items","items","item" }) :
                   "The counters are made of simple wood, with flat tops to allow "
                   "storage.  Some items, useful in a hospital, sit out on top.  "
                   "Among them are some unprepared bandages and empty food trays.",
                ({ "unprepared bandages","bandage","bandages" }) :
                   "Sitting out and waiting for completion, some unprepared bandages "
                   "are on the counter.",
                ({ "empty food trays","trays","tray" }) :
                   "Flat pieces of wood with a rim to keep things from falling off, "
                   "empty food trays sit in stacks on the counters.",
           ]) );
   SetItemAdjectives( ([
                         "items" : ({ "hospital","useful" }),
                         "bandages" : ({ "unprepared" }),
                         "trays" : ({ "empty","food" }),
                    ]) );
   SetListen( ([
                 "default" : "The hospital room upstairs clamors with much activity.",
            ]) );
   SetExits( ([
                "east" : PR + "/room2",
           ]) );
   SetInventory( ([
                    PN + "/human" : 4,
                    PN + "/doctor" : 3,
                    PN + "/patient" : 3,
                    PO + "/cabinet" : 2,
               ]) );
}
