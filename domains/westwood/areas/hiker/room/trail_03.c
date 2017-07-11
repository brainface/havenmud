#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   
   SetLong("The trail turns to the northeast and southeast here, curving "
           "on the incline.  Boards of wood make a flat, even surface to "
           "walk on, growing longer as the ground flattens to the "
           "northeast and southeast; here the ground is steep and the "
           "planks of wood make stair-steps going up.");
   SetItems( ([
                ({ "narrow trail","trail" }) :
                   (: GetLong :),
                ({ "boards of wood","boards","board","planks","plank",
                   "wood" }) :
                   "The boards form what looks like a staircase as they "
                   "head up and around to the northeast from the "
                   "southeast.  On either end, used to join them together "
                   "and raise the level up to the next plank, wooden "
                   "supports are used.",
                ({ "wooden supports","wood supports","wood",
                   "wood support","wooden support","supports",
                   "support" }) :
                   "The supports are made of longer boards that were "
                   "chopped up into small squares and stacked.",
                ({ "steep ground","ground" }) :
                   "The ground inclines upward from the southeast to the "
                   "northeast, causing the boards to be short and go up "
                   "in a stair-like manner.  It is green and firm beneath "
                   "the planks.",
           ]) );
   SetItemAdjectives( ([
                         "board" : ({ "boards of","board of","planks of",
                                      "plank of","wooden","wood" }),
                         "support" : ({ "wooden","wood" }),
                    ]) );
   SetSmell( ([
                "default" : "Fresh air fills the senses with life.",
           ]) );
   SetListen( ([
                 "default" : "Something rustles in the distance, then "
                    "abruptly ceases.",
            ]) );
   SetExits( ([
                "southeast" : H_ROOM + "trail_02",
                "northeast" : H_ROOM + "trail_04",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 2+random(1),
               ]) );
}
