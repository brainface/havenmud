#include <lib.h>
#include <domains.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetShort("in Parva");
   SetLong("Parva is a dusty, dirty, falling-apart town "
           "that sits right on the ocean.  Buildings are "
           "to the north and south.  The northern building is "
           "small and obsidian.  The southern building is very "
           "long and appears to be a hospital run by Eclats.  "
           "The road runs east and west, but is currently closed to the west.");
   SetItems( ([
                ({ "Parva","parva","town","road" }) :
                   (: GetLong :),
                ({ "beautiful ocean","ocean" }) :
                   "The ocean is beautiful.  One can "
                   "see it sparkling at the end of the "
                   "road.",
                ({ "northern building","building",
                   "shrine" }) :
                   "The building to the north is small "
                   "and obsidian.  It looks like a shrine "
                   "of some sort.",
                ({ "eclat hospital","building", "hospital" }) :
                   "The hospital is to the south of this road, and is a very "
                   "large building.  It has an entrance on this side.",
           ]) );
   SetItemAdjectives( ([
                         "parva" : ({ "dusty","dirty",
                                      "falling-apart", }),
                         "hospital" : ({ "eclat","large" }),
                         "shrine" : ({ "small","obsidian" }),
                    ]) );
   SetSmell( ([
                "default" : "Salt and ocean ride in "
                   "on the wind.",
           ]) );
   SetListen( ([
                 "default" : "Waves roar in the "
                    "distance.",
            ]) );
   SetExits( ([
                "east" : P_ROOM + "/path5",
           ]) );
   SetEnters( ([
                 "shrine" : PS_ROOM + "/soir_church",
               "hospital" : HAVENWOOD_AREAS + "parvahosp/room/entrance",
            ]) );
   SetInventory( ([
                    P_NPC + "/cit" : 3,
               ]) );
}
