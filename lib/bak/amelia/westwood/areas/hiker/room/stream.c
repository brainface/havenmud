#include <lib.h>
inherit LIB_FISHING;
#include "../hiker.h"

static void create() {
   fishing::create();
   SetShort("in a stream");
   SetDomain("WestWood");
   SetLong("The stream is wide and shallow here, as opposed to being "
           "skinny and deep.  It goes about six or seven feet from "
           "bank to bank, the water brushing noisily up against the "
           "edges and eroding them further.  A log dips into the water, "
           "balance carefully against the bridge which seems too "
           "far up to make it onto directly from the water.");
   SetItems( ([
                ({ "west wood","wood","woods","forest" }) :
                   (: GetLong :),
                ({ "stream banks","edges","edge","bank","banks",
                   "dirt" }) :
                   "The dirt that makes the banks of this stream is "
                   "very wet and seems to be slowly eroding before "
                   "one's eyes.",
                ({ "fallen log","log" }) :
                   "The log is slowly rotting in its half-upright "
                   "position.  It leans heavily against the strong "
                   "wooden bridge above, and one could probably go "
                   "up onto it.  It looks mostly safe.",
                ({ "solid wooden bridge","solid bridge","wooden bridge",
                   "bridge","wood" }) :
                   "The bridge is made of wood, and seems quite solid and "
                   "sturdy.  A fallen log rests against it, depending "
                   "on it to protect it from being swept away into "
                   "the water.  The log could probably get used as a "
                   "halfway point to getting to the bridge, as it is "
                   "too high to go on to directly here.  In fact, "
                   "it might even be possible to go under the bridge, "
                   "heading to the west upstream!",
           ]) );
   SetItemAdjectives( ([
                         "bridge" : ({ "solid","wooden","wood" }),
                    ]) );
   SetListen( ([
                 "default" : "The streams gurgles along happily "
                    "and noisily.",
            ]) );
   SetSmell( ([
                "default" : "Rushing water gives a peculiar smell to an "
                   "area, or perhaps a peculiar lack of smell.",
           ]) );
   SetObviousExits("up");
   SetExits( ([
                "up" : H_ROOM + "log",
                "west" : H_ROOM + "spiderr",
           ]) );
   SetInventory( ([
                    H_NPC + "fisha" : 3+random(4),
                    H_NPC + "fishb" : 1+random(2),
                    H_ROOM + "water" : 1,
               ]) );
   SetSpeed(1);
   SetFish( ([
               H_OBJ + "fisha" : 110,
               H_OBJ + "fishb" : 110,
          ]) );
   SetChance(30);
   SetMaxFishing(20);
}
