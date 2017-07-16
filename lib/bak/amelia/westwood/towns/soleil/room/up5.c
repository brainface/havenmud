#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   SetDomain("WestWood");
   SetShort("on a high platform");
   SetLong("This is the end of the string of "
           "rope bridges on the second level of "
           "Soleil.  One can only exit to the "
           "west, where a rope bridge hangs "
           "off the end of the platform.  There "
           "is a building to the south.");
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
                   "The bridge is made from "
                   "tough, sturdy ropes, and "
                   "though it wavers some in "
                   "the wind, it is very safe.",
                ({ "north building","buildings",
                   "building","inn" }) :
                   "There is an inn on the north "
                   "side of the platform.",
           ]) );
   SetItemAdjectives( ([
                         "bridges" : ({ "rope","tough",
                                        "sturdy", }),
                         "platform" : ({ "circular",
                                         "second","high" }),
                         "trees" : ({ "coniferous" }),
                         "north building" : ({ "north",
                            "player" }),
                    ]) );
   SetSmell( ([
                "default" : "Spruce smells fill the air.",
           ]) );
   SetListen( ([
                 "default" : "Trees shake in the wind.",
            ]) );
   SetExits( ([
                "west" : S_ROOM + "up3",
           ]) );
   SetEnters( ([
                 "inn" : S_ROOM + "pinn1",
            ]) );
   SetInventory( ([
                    S_NPC + "citizenf" : 1,
                    S_NPC + "music" : 2,
               ]) );
}
