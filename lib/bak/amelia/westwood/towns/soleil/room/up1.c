// Second level of Soleil.  Amelia@Haven, Jan 1999
#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   SetDomain("WestWood");
   SetClimate("temperate");
   SetShort("a high platform");
   SetLong("Trees spring into the air around this platform, "
           "their branches supporting Soleil.  Buildings "
           "blend in with the green spruce needles clinging "
           "to the dark branches.  Rope bridges go west and "
           "east from this platform.  A ladder leads down.");
   SetItems( ([
                ({ "high platform","platform","soleil" }) :
                   (: GetLong :),
               ({ "coniferous trees","tree","needles","needle",
                  "branches","branch" }) :
                  "The coniferous trees grow all around this "
                  "platform.  Green, pointed needles cling "
                  "to the branches, which are a dark brown "
                  "in color.  The rope bridges and platforms "
                  "attach to the trees for support.",
                ({ "rope bridges","bridges","bridge","rope" }) :
                  "Rope bridges go to the west and east from "
                  "this platform.  They are the only way off, "
                  "excluding the ladder.",
                ({ "Soleil buildings","building","buildings" }) :
                   "The buildings blend in with the surroundings.  "
                   "There is one to the north that looks like it "
                   "can be entered from here.",
                ({ "north building","building",
                   "hall" }) :
                   "The Music Hall is to the north.  "
                   "It blends in with the trees "
                   "well.",
                ({ "wooden ladder","ladder" }) :
                   "The ladder disappears into the trees "
                   "below.  It leads to the rest of Soleil.",
          ]) );
   SetItemAdjectives( ([
                         "platform" : ({ "high" }),
                             "north building" : ({ "music","north" }),
                     "buildings": ({ "soleil" }),
                         "tree" : ({ "coniferous","dark",
                            "green","pointed","spruce","brown" }),
                         "bridge" : ({ "rope" }),
                         "ladder" : ({ "wooden","wood" }),
                ]) );
   SetSmell( ([
                "default" : "A pine scent fills the air.",
           ]) );
   SetListen( ([
                 "default" : "The branches rustle in the wind.",
            ]) );
   SetExits( ([
                "west" : S_ROOM + "up2",
                "east" : S_ROOM + "up3",
                "down" : S_ROOM + "tree_b",
          ]) );
   SetInventory( ([
                    S_NPC + "citizenf" : 2,
                    S_NPC + "citizenm" : 2,
			S_NPC + "guard_gate" : random(3),
               ]) );
   SetEnters( ([
                 "hall" : S_ROOM + "hall"
            ]) );
}
