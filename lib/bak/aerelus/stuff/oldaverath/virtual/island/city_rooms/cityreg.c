#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("City Registrar's Office");
   SetLong("Prominently displayed above the brick fireplace, an elk's head "
           "stares with empty eyes at the City Registrar's Office.  A "
           "warm rug covers part of the wooden floor.  Large windows "
           "allow natural light to spill in from the west, and heavy "
           "doors provide access to the outside world.");
   SetItems( ([
                ({ "city registrar's office","office" }) : (: GetLong :),
                ({ "brick fireplace","fireplace","fire","bricks","brick",
                   "coals","coal","ash" }) :
                   "The fire burns steadily, radiating heat in tiny waves.  "
                   "Coals glow in the bottom of the fireplace among piles "
                   "of ash, although none of it has stained the tiles in "
                   "front of the fireplace.",
                ({ "fireplace tiles","tiles","tile" }) :
                   "The brick tiles sit in front of the fireplace, preventing "
                   "the coals from setting fire to the entire house.",
                ({ "elk's head","elk","head","antlers","antler" }) :
                   "Mounted on a solid slab of wood, the elk's head "
                   "rests above the heavy doors.  Its antlers stretch "
                   "out a few feet on either side.",
                ({ "warm rug","floor","rug" }) :
                   "A warm rug of animal fur covers part of the chill wooden "
                   "floor.  Its cozy fur has a well-worm appearance, fading "
                   "from brown to grey across the the length of it.",
                ({ "large windows","windows","window" }) :
                   "The windows open up the west side of the room, letting "
                   "light in from the outside.  The pair begin about "
                   "four feet off of the ground and stretch another four "
                   "feet high.",
                ({ "heavy doors","doors","door" }) :
                   "The heavy doors are propped open, leading to the "
                   "street outside.",
           ]) );
   SetItemAdjectives( ([
                         "office" : ({ "city","registrar's" }),
                         "fireplace" : ({ "brick", }),
                         "tile" : ({ "fireplace","brick" }),
                         "head" : ({ "elk's","elk" }),
                         "rug" : ({ "warm","wooden" }),
                         "windows" : ({ "large" }),
                         "doors" : ({ "open","heavy" }),
                    ]) );
   SetSmell( ([
                "default" : "A dusty smell mingles with the scent of burning "
                            "wood.",
           ]) );
   SetListen( ([
                 "default" : "The fire crackles as it burns.",
            ]) );
   SetExits( ([
                "out" : AVERATH_ISLAND + "-1,0,0",
           ]) );
   SetInventory( ([
                    AVERATH_NPC + "mayor" : 1,
               ]) );
}
