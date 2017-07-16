#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   
   SetShort("on a high platform");
   SetLong("Rope bridges hang from the platform, "
           "which rests on the trees.  They "
           "lead off to the west and east.  "
           "Buildings perch to both sides of "
           "the platform; the north one "
           "appears frequently used.");
   SetItems( ([
                ({ "high platform","platform",
                   "platforms","level","Soleil" }) :
                   (: GetLong :),
                ({ "coniferous trees","trees","tree" }) :
                   "The trees are all coniferous "
                   "here, growing tall and strong "
                   "in the rich soil below "
                   "Soleil.  The platforms hang "
                   "here in the air with the support "
                   "of the trees.",
                ({ "rope bridges","bridges","bridge",
                   "rope" }) :
                   "The bridges are made from "
                   "tough, sturdy ropes, and "
                   "though they waver some in "
                   "the wind, they are very safe.",
                ({ "south building","buildings",
                   "building" }) :
                   "The building to the south "
                   "appears unfinished.",
                ({ "north building","buildings",
                   "building","hall","store" }) :
                   "Footsteps lead into the "
                   "music store to the north.  "
                   "It looks like it's frequented "
                   "often.",
           ]) );
   SetItemAdjectives( ([
                         "south building" : ({ "unfinished" }),
                         "bridges" : ({ "rope","tough",
                                        "sturdy", }),
                         "platform" : ({ "circular",
                                         "second","high" }),
                         "trees" : ({ "coniferous" }),
                         "north building" : ({ "north",
                            "music" }),
                    ]) );
   SetSmell( ([
                "default" : "Alive, forest smells "
                   "fill the air.",
           ]) );
   SetListen( ([
                 "default" : "Wind ruffles the "
                    "trees.",
            ]) );
   SetExits( ([
                "east" : S_ROOM + "up5",
                "west" : S_ROOM + "up1",
           ]) );
   SetEnters( ([
                 "hall" : S_ROOM + "musicstore",
            ]) );
   SetInventory( ([
                    S_NPC + "citizenm" : 1,
                    S_NPC + "citizenf" : 1,
                    S_NPC + "music" : 2,
               ]) );
}
