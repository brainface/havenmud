#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("the bedroom");
   SetLong("A cheery fire dances in the stone fireplace in the south "
           "wall.  Small tapestries hang to either side, and tucked into "
           "the northeast corner of the room is a splendid bed, looking "
           "smooth as an ocean is with its waves by the many quilts piled "
           "on it haphazardly.  To the west is an open doorway; it is the "
           "only exit from this room.");
   SetItems( ([
                ({ "open doorway","open door","doorway","door" }) :
                   "The doorway has no door attached to it, but "
                   "isn't blocked off and leads into the room to the west "
                   "from here.  It is the only exit from this room, and "
                   "some of the life from the fire reflects off of it, "
                   "colored orange.",
                ({ "splendid bed","bed","quilts","quilt","northeast corner",
                   "corner" }) :
                   "The bed is large in size, and looks to be very "
                   "comfortable and very warm, even in this stone cold "
                   "castle.  The quilts that are visible (without climbing "
                   "into the bed and pushing them around) are all made "
                   "with delicate care and attention to details.",
                ({ "small tapestries","small tapestry","tapestries",
                   "tapestry","south wall","wall","right tapestry",
                   "left tapestry","dazzling lady","lady","flowers",
                   "flower","pure white unicorn","pure unicorn",
                   "white unicorn","fleet of knights","castle",
                   "fleet","knights","knight" }) :
                   "The two tapestries are similar, but only in their "
                   "fine quality and general theme.  In the left one, "
                   "a dazzling lady is holding out flowers to a "
                   "pure white unicorn.  In the right tapestry, a fleet "
                   "of knights is returning home to a castle.",
                ({ "bedroom","room","stone cold castle","cold stone castle",
                   "castle","cold castle","stone castle" }) :
                   (: GetLong :),
                ({ "cheery fire","fire","stone fireplace","fireplace",
                   "stone","south wall","wall" }) :
                   "Flickering and dancing about happily, the fire "
                   "is such that enchants one's eyes after being out "
                   "in the cold for a long time.  It casts an almost "
                   "erie orange light on much of the room.",
           ]) );
   SetExits( ([
                "west"  : VC_ROOM + "/llroom2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/maid" : 1,
               ]) );
}
