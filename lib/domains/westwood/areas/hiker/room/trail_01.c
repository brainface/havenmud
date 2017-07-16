#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   
   SetLong("Space to stand exists on planks of wood that are about "
           "six feet long, standing on supports of other planks that "
           "were chopped up.  The boards are longer to the southeast, "
           "where the ground slopes more gently than it does to the "
           "west, which is the direction the boards continue in.  "
           "Trees and underbrush crowd close to the boards here, and "
           "the ground underneath is carpeted with grass.");
   SetItems( ([
                ({ "narrow trail","trail","space" }) :
                   (: GetLong :),
                ({ "sloping ground","ground" }) :
                   "The ground slopes down to the southeast and "
                   "up to the west.  To the north, a skimpy trail "
                   "is just barely visible, scrambling up a steeper "
                   "incline.",
                ({ "skimpy trail","trail" }) :
                   "To the north is another trail, unvarnished by the "
                   "wooden planks and uncleared.  It is like a "
                   "little stream that trickled down, clearing a way "
                   "through the brush, that has proceeded to be used "
                   "for quick access to places higher up the trail.",
                ({ "planks of wood","wood","plank","planks","boards",
                   "board" }) :
                   "The planks of wood have been set solidly on "
                   "supports made from planks that have been chopped "
                   "up.  They are shorter to the west and longer to "
                   "the southeast.",
                ({ "wooden supports","support",
                   "supports","wood","planks","plank","boards","board" }) :
                   "The supports are used to hold up the planks of "
                   "wood.  They are stuck at each end of the planks, "
                   "creating miniature steps as two planks are tacked "
                   "together.",
                ({ "west wood","wood","woods","tree","trees","underbrush",
                   "brush" }) :
                   "The West Wood surrounds this area, and is too big "
                   "to take it completely from here.  The trees are "
                   "deciduous in this area, and thick underbrush grows "
                   "around them.  A skimpy trail can almost be seen going "
                   "north through it.",
                ({ "green grass","grass" }) :
                   "Grass flourishes under the planks of wood.",
           ]) );
   SetItemAdjectives( ([
                         "plank" : ({ "plank of","wood","wooden"}),
                         "support" : ({ "wooden","wood" }),
                    ]) );
   SetSmell( ([
                "default" : "Grassy smells of fresh dirt and growing "
                            "things drift up from below.",
           ]) );
   SetListen( ([
                 "default" : "Something struggles in the brush to the "
                    "north.",
            ]) );
   SetObviousExits("southeast, west");
   SetExits( ([
                "southeast" : H_ROOM + "trailhead",
                "west"      : H_ROOM + "trail_02",
                "north"     : H_ROOM + "shortcut",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 2,
               ]) );
}
