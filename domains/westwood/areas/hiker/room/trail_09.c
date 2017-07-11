#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   
   SetLong("The West Wood pulls up against the planks of wood that mark "
           "the trail, reaching its westward side a little farther "
           "north.  To the west and east, the land is still a meadow, "
           "and the West Wood has pulled off from the east side of the "
           "trail.  The planks go in a straight line to the north and "
           "south, with open meadow to the east and west.");
   SetItems( ([
                ({ "meadow trail","trail","meadow" }) :
                   (: GetLong :),
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The trees pull close to the trail slightly north "
                   "from this exact point, leaving a way to the west "
                   "open.  They are all deciduous.",
                ({ "planks of wood","wood",
                   "plank","plank","board","boards" }) :
                   "Boards made up the trail and mark it clearly in "
                   "their straight north-south line.  They are each "
                   "about seven feet long and one foot wide.",
           ]) );
   SetItemAdjectives( ([
                         "meadow" : ({ "open","meadow" }),
                         "wood" : ({ "planks of","plank of","wooden",
                                     "board of","boards of","wood" }),
                    ]) );
   SetListen( ([
                 "default" : "The trees click together in the wind.",
            ]) );
   SetSmell( ([
                "default" : "The world smells earthy and fresh.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "trail_10",
                "south" : H_ROOM + "trail_08",
                "east"  : H_ROOM + "meadow_5",
                "west"  : H_ROOM + "meadow_1",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : random(3),
               ]) );
}
