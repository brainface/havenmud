#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(39);
   SetShort("inside a tavern");
   SetLong("The room in here is quite clean, considering that right "
           "outside is a muddy forest.  Footprints have been tracked "
           "all over the floor and some stray leaves have floated in "
           "through the doorway, riding on gusts of wind.  A long "
           "counter is up near the wall in the northeast; that wall is "
           "the only flat one since the rest are in a semi-circular "
           "curve.  A ladder near the counter leads up.");
   SetItems( ([
                ({ "wooden ladder","ladder" }) :
                   "Next to the long counter is a ladder leading up to "
                   "another section of this tavern.  It is simple and "
                   "plain.",
                ({ "long counter","counter" }) :
                   "The counter provides lots of space for sitting at "
                   "and setting stuff on.  It is up against the "
                   "northeast wall, which is really the only flat "
                   "wall in this tavern.",
                ({ "northeast wall","wall","flat wall" }) :
                   "The northeast wall is flat and long, with the "
                   "counter in front of it.  As such, it is peculiar, "
                   "since the rest of the walls are curved together.  "
                   "It is as if a slice of a circle was taken out at that "
                   "end, and replaced by a single wall.",
                ({ "semi-circular wall","semi-circular curve","curve",
                   "wall","walls","curved wall" }) :
                   "While the northeast wall is flat and straight, "
                   "the rest of the tavern is in a semi-circular curve.  "
                   "It is as if someone built a circular building, "
                   "then ended up chopping off the northeast corner of "
                   "it.  An open doorway is in the middle of the "
                   "curved wall.",
                ({ "open doorway","open door","door","doorway" }) :
                   "In the curved wall of the tavern, opposite the long "
                   "counter and flat wall, is an open doorway leading "
                   "out.  Aside from the ladder up near the "
                   "counter, it is the only exit.",
                ({ "tavern floor","floor" }) :
                   "The floor of the tavern is messy and dirty; it "
                   "is covered with brown leaves and muddy footprints.  "
                   "Most is concentrated near the doorway.",
                ({ "stray leaves","stray leaf","leaves","leaf",
                   "brown leaves","brown leaf","little pieces",
                   "piece","pieces","little piece" }) :
                   "Brown leaves shrivel up along the floor, some "
                   "having already fallen apart into little pieces.",
                ({ "eclatish tavern","pub","bar","tavern","room" }) :
                   (: GetLong :),
                ({ "muddy forest","forest","outside" }) :
                   "That is outside, and not visible from here.",
                ({ "muddy footprints","footprints","muddy footprint",
                   "footprint","prints","print","muddy prints",
                   "muddy print","mud","boots","boot","bare feet",
                   "feet","bare foot","foot" }) :
                   "Footprints of boots and bare feet are scattered "
                   "all over the floor.  There are many different "
                   "boot and foot types shown, but all are hard to "
                   "see through the other prints.",
           ]) );
   SetListen( ([
                 "default" : "Merriment and joy can be heard in the "
                    "laughter near here.",
            ]) );
   SetExits( ([
                "out" : M_ROOM + "plat_c",
                "up"  : M_ROOM + "tav_ecl",
           ]) );
   SetInventory( ([
                    M_NPC + "bar_d" : 1,
                    M_NPC + "trav_wor" : random(3)+2,
                    M_NPC + "monk_h" : 2,
               ]) );
}