#include <lib.h>
inherit LIB_FISHING;
#include "../hiker.h"

static void create() {
   fishing::create();
   SetShort("on a bridge overlooking a stream");
   SetDomain("WestWood");
   SetLong("The wooden planks become short, choppy steps to make it "
           "up onto this plain wooden bridge.  A trickling stream "
           "flows beneath, and it is probably about six or seven feet "
           "wide, with one to two foot banks.  A fallen log rests up "
           "against the bridge, its other end down in the water.");
   SetItems( ([
                ({ "stream banks","banks","bank",
                   "edge","edges" }) :
                   "The banks of the stream go about one to two feet "
                   "up into the air above the water.  They are wet and "
                   "seem to be slowly backing away as the river erodes "
                   "its edges.",
                ({ "trickling stream","stream","water","river" }) :
                   "The stream is beneath the bridge, and one could "
                   "probably make it down there from this bridge.  "
                   "The other end of a fallen log is also in the stream.  "
                   "Jumping down to the water from here might make "
                   "it difficult to get back up, however, unless "
                   "one can scramble on the log.",
                ({ "narrow trail","trail" }) :
                   (: GetLong :),
                ({ "plain wooden bridge","bridge","wood" }) :
                   "The bridge is made from the same planks the trail "
                   "is, with the set-up being slightly different to "
                   "insure strong support over the water.",
                ({ "wooden planks","plank","plank","step",
                   "boards","board","step","wood" }) :
                   "The planks used to make the trail are fairly "
                   "long, until right before the bridge.  At that "
                   "point, they abruptly become about a foot long and "
                   "are propped up into steps.",
           ]) );
   SetItemAdjectives( ([
                         "bridge" : ({ "plain","wooden" }),
                         "bank" : ({ "stream" }),
                         "planks" : ({ "wooden","wood","short",
                                       "choppy","planks of","plank of",
                                       "board of","boards of" }),
                         "bank" : ({ "stream" }),
                    ]) );
   SetListen( ([
                 "default" : "The stream trickles along below.",
            ]) );
   SetSmell( ([
                "default" : "The river adds a peculiar lack of smell "
                   "to this area.",
           ]) );
   SetExits( ([
                "south" : H_ROOM + "trail_11",
                "north" : H_ROOM + "trail_13",
           ]) );
   SetInventory( ([
                    H_ROOM + "log_d" : 1,
                    H_NPC + "fisher" : 2,
                    H_NPC + "swimboy" : 1,
               ]) );
   SetSpeed(2);
   SetFish( ([
               H_OBJ + "fisha" : 120,
               H_OBJ + "fishb" : 20,
          ]) );
   SetChance(50);
   SetMaxFishing(5);
}
