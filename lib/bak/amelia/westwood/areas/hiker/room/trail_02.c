#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("The boards continue to be set up along here, stretching out "
           "with a dry and flat area to walk on heading east and "
           "northwest.  The West Wood surrounds the trail with its "
           "trees and thick underbrush, preventing movement in all "
           "directions not paved with wood.");
   SetItems( ([
                ({ "narrow trail","trail","path","area" }) :
                   (: GetLong :),
                ({ "wooden boards","wood boards","wooden board",
                   "wood board","planks","plank","wood","wood" }) :
                   "The wooden boards pave the trail, making it "
                   "flat and easy to walk on.  Supports hold them up "
                   "at either end and join them together into straight "
                   "lines.  Each is about six feet long here, growing "
                   "shorter as the trail turns northwest.",
                ({ "wooden supports","wood","support",
                   "supports","boards","board" }) :
                   "The wooden supports were made by chopping up the "
                   "other boards and stacking them.",
                ({ "west wood","wood","woods","tree","trees",
                   "thick underbrush","brush","underbrush",
                   "thick brush","forest" }) : 
                   "The West Wood is the forest that surrounds this "
                   "trail.  It is thick and unruly but has been pushed "
                   "back by this trail.",
           ]) );
   SetItemAdjectives( ([
                         "trail" : ({ "narrow","dry","flat" }),
                         "support" : ({ "wooden","wood" }),
                         "board" : ({ "wooden","wood","plank of",
                                      "planks of" }),
                    ]) );
   SetSmell( ([
                "default" : "The world smells earthy.",
           ]) );
   SetListen( ([
                 "default" : "The wind rushes around noisily.",
            ]) );
   SetExits( ([
                "east"      : H_ROOM + "trail_01",
                "northwest" : H_ROOM + "trail_03",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 1+random(3),
               ]) );
}
