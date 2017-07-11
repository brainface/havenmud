#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   
   SetShort("on a high platform");
   SetLong("This platform is part of the second level "
           "of platforms in Soleil.  There are "
           "more, slightly hidden by trees, to the "
           "west and east.  Rope bridges connect "
           "the circular platforms, and buildings "
           "squat on either side of this platform.");
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
                ({ "unfinished buildings","buildings",
                   "building" }) :
                   "The buildings on either side of "
                   "this platform appear unfinished.",
           ]) );
   SetItemAdjectives( ([
                         "buildings" : ({ "unfinished" }),
                         "bridges" : ({ "rope","tough",
                                        "sturdy", }),
                         "platform" : ({ "circular",
                                         "second","high" }),
                         "trees" : ({ "coniferous" }),
                    ]) );
   SetSmell( ([
                "default" : "Alive, forest smells "
                   "fill the air.",
           ]) );
   SetInventory( ([
                    S_NPC + "citizenm" : 1,
                    S_NPC + "citizenf" : 1,
                    S_NPC + "music" : 1,
               ]) );
   SetListen( ([
                 "default" : "Wind ruffles the "
                    "trees.",
            ]) );
   SetExits( ([
                "east" : S_ROOM + "up1",
                "west" : S_ROOM + "up4",
           ]) );
}
