#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("in a meadow");
   SetDomain("WestWood");
   SetLong("A field of chocolate lilies shows itself in the slightly "
           "damp earth particular to this meadow.  It continues to both "
           "the north and south, but the lilies die out in both "
           "directions, while continuing with the meadow to the east.  "
           "A trail seems to wind around to the west, marked out by "
           "some sort of boards.  To the south, there seems to "
           "a platform.");
   SetItems( ([
                ({ "wide meadow","meadow","field" }) :
                   (: GetLong :),
                ({ "trail of boards","trail","boards","board" }) :
                   "There is a trail to the west that seems to be "
                   "present only at the sufferance of a number of "
                   "boards used to build it.  Nothing more can be seen from "
                   "here except that it travels in a north-south "
                   "direction.",
                ({ "chocolate lilies","chocolate lilies","lily",
                   "lilies","chocolate","flowers","flower" }) :
                   "The lilies are a deep, chocolate brown and do not "
                   "have much of a smell.  They are all over this meadow, "
                   "with little room for other flowers left.  Grass "
                   "grows amongst them.",
                ({ "green grass","grass" }) :
                   "The grass is a plain, hardy variety that has taken " 
                   "a good solid hold on this meadow.",
                ({ "wooden platform","platform","wood","board",
                   "boards" }) :
                   "To the south, there seems to be a wooden platform "
                   "built of the same sort of boards that form the "
                   "trail to the west.  It sits complacently in the "
                   "middle of its meadow, waiting to be used.",
                ({ "slightly damp earth","earth","ground","dirt" }) :
                   "The dirt is covered with grass and lilies, but "
                   "it is apparent that it is rather damp earth.",
             ]) );
   SetItemAdjectives( ([
                         "platform" : ({ "wooden","wood" }),
                         "earth" : ({ "slightly","damp","rather" }),
                         "grass" : ({ "plain","hardy","green" }),
                         "lilies" : ({ "deep","brown","chocolate" }),
                    ]) );
   SetListen( ([
                 "default" : "A wind skips across the land, leaving the "
                    "lilies and grass to rattling against each other.",
            ]) );
   SetSmell( ([
                "default" : "The world is pure and clean in scent.",
                "lily" : "The lilies have no appreciable odor to them.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "meadow_5",
                "south" : H_ROOM + "meadow_7",
                "west"  : H_ROOM + "trail_08",
                "east"  : H_ROOM + "meadow_9",
           ]) );
   SetInventory( ([
                    H_NPC + "pic_kid" : 1,
                    H_NPC + "grub" : 1,
               ]) );
}
