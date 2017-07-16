#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("in a meadow");
   
   SetLong("The West Wood is formed of many squatting trees to the "
           "north and east, while the meadow runs smoothly to "
           "the northwest, west, and south.  Grass grows thick on the "
           "damp ground, with various flowers dotting the green masses.  "
           "Some chocolate lilies grow to the south.");
   SetItems( ([
                ({ "smooth meadow","meadow" }) :
                   (: GetLong :),
                ({ "west wood","wood","woods","squatting trees",
                   "squatting tree","trees","tree" }) :
                   "The West Wood is to the north and the east, but "
                   "instead of its characteristically towering "
                   "trees, the trees here are short and seems to "
                   "scrunch down lower to the ground than they "
                   "have in other areas.",
                ({ "thick grass","grass","green masses","green mass",
                   "masses","mass","damp ground","ground" }) :
                   "The grass covers the meadow, hiding the ground from "
                   "sight.  It spreads out even more to the south and "
                   "west, but to the south it seems to be speckled with "
                   "brown, much like the chocolate lilies growing here.",
                ({ "chocolate lilies","chocolate lily","lilies","lily" }) :
                   "The chocolate lilies are a deep, rich brown, and "
                   "seem to flourish most of all to the south.  "
                   "Other flowers grow around this area, too.",
                ({ "various flowers","flower","flowers" }) :
                   "Many different flowers grow around here, but the only "
                   "constant is that of the chocolate lilies to the "
                   "south.  The rest are just a mixture of different "
                   "kinds, hidden among the grass.",
           ]) );
   SetItemAdjectives( ([
                         "trees" : ({ "short" }),
                         "lilies" : ({ "deep","rich","brown","chocolate" }),
                    ]) );
   SetSmell( ([
                "default" : "The air has the fresh scent of the outdoors.",
           ]) );
   SetExits( ([
                "northwest" : H_ROOM + "meadow_4",
                "west"      : H_ROOM + "meadow_5",
                "south"     : H_ROOM + "meadow_9",
           ]) );
   SetInventory( ([
                    H_NPC + "doe" : random(3)+5,
                    H_NPC + "stag" : 2,
               ]) );
}
