#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   
   SetLong("The ground here is firm and solid, but it gets all muddy to "
           "the west.  It is also fairly rocky, with a number of little "
           "stones waiting on the chance to trip someone or poke them in "
           "the foot.  Trees of the West Wood surround the trail as it "
           "heads east and west, and to the east there seems to be "
           "some sort of structure the trail leads to.");
   SetItems( ([ 
                ({ "solid trail","trail" }) :
                   (: GetLong :),
                ({ "firm ground","ground","mud" }) :
                   "The ground is nice and solid.  This quality is "
                   "probably encouraged most of all by the "
                   "rocks scattered all over it, half-embedded into the "
                   "ground.  To the west, it turns to mud, but it "
                   "remains solid to the east.",
                ({ "little stones","stones","rocks","stone","rock",
                   "little stone" }) :
                   "The stones are of all different shapes and sizes, but "
                   "remain mostly small and sharp with a general grey "
                   "shade to them.  They are all over the trail, just "
                   "waiting to trip someone or poke their foot with their "
                   "sharpness.  There don't seem to be any rocks to the "
                   "west.",
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The trees grow around the trail, giving it plenty of "
                   "space to continue its westward voyage, but not "
                   "leaving much room to the west around the mud.",
                ({ "eastern structure","structure" }) :
                   "The structure to the east is wooden and not too "
                   "large, but significant enough in size to be noticable "
                   "from here.  The trail seems to go up on it.",
           ]) );
   SetListen( ([
                 "default" : "The wind blows through the trees.",
            ]) );
   SetSmell( ([
                "default" : "The world smells clean and fresh.",
           ]) );
   SetExits( ([
                "east" : H_ROOM + "porch",
                "west" : H_ROOM + "trail_15",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : random(2),
               ]) );
}
