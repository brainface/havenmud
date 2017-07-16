#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("Wooden boards plod in a straight line through this meadow, "
           "cutting along and leaving life split in a small patch that is "
           "less heathy directly beneath the planks, and in the huge "
           "meadow that abounds with fresh air and robust healthiness.  "
           "The West Wood is visible here in the form of a few, small "
           "trees growing about in the meadow, but mostly grass and "
           "flowers are what grows here.  Nothing blocks movement to "
           "the north and south along the planks, or into the meadow "
           "to the east or west.");
   SetItems( ([
                ({ "fresh grass","grass" }) :
                   "Grass grows all over the meadow, and is, in fact, "
                   "the staple plant of the area.  It has withered from " 
                   "lack of sunlight and proper nutrients directly "
                   "beneath the wooden planks, but flourishes in the "
                   "rest of the meadow.",
                ({ "beautiful wildflowers","flower",
                   "flowers","wildflower","wildflowers" }) :
                   "Many different types of flowers live in the "
                   "meadow, but all are wild and all grow free.  They "
                   "are scattered haphazardly all over, among the "
                   "grass and under the trees and huddled against the "
                   "wooden planks.",
                ({ "meadow trail","trail" }) :
                   (: GetLong :),
                ({ "wooden boards","board","boards","planks",
                   "plank","wood" }) :
                   "The boards are about a foot across and eight or "
                   "nine feet long.  They are held up, sagging in the "
                   "middle, by supports placed at either end which are "
                   "also used to connect the individual boards into "
                   "a straight line.",
                ({ "wood supports","supports","support" }) :
                   "The supports are made of boards, but are about a "
                   "foot square, so other boards must have been "
                   "chopped up into a number of pieces to make the "
                   "supports.  The supports were then stacked and "
                   "placed at either end of the planks, holding them "
                   "about half of a foot into the air at the ends.",
                ({ "west wood","woods","wood","tree","trees", }) :
                   "No tree has gained a strong, solid hold in the "
                   "meadow, but a few that are short and almost "
                   "stunted grow in the meadow.",
                ({ "huge meadow","meadow","field" }) :
                   (: GetLong :),
           ]) );
   SetItemAdjectives( ([
                         "meadow" : ({ "huge","beautiful" }),
                         "trees" : ({ "small" }),
                         "supports" : ({ "wood","wooden" }),
                         "flowers" : ({ "beautiful","wild" }),
                         "boards" : ({ "wooden","wood","planks of",
                                       "boards of","plank of",
                                       "board of" }),
                    ]) );
   SetListen( ([
                 "default" : "The air tickles the grass in a quiet way, "
                    "but it produces a soft sound.",
            ]) );
   SetSmell( ([
                "default" : "Fresh air and rich dirt and healthy grass "
                   "and beautiful wildflowers all compete with "
                   "conflicting smells that meld together to form the "
                   "unique scent of a meadow.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "trail_09",
                "south" : H_ROOM + "trail_07",
                "east"  : H_ROOM + "meadow_6",
                "west"  : H_ROOM + "meadow_2",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 2+random(4),
               ]) );
}
