
/*  My Angel Area.  A small forest.
 *  Edited further by Vaashan@Haven 9/01/09
 */
#include <lib.h>
#include "../vaashan.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(15);
  SetClimate("indoors");
  SetShort("a dank cave");
  SetLong(
     "This cave opens up into a dank and poorly lit area. There are bones "
     "scattered about the floor, which is slanted noticeably downward. The "
     "back of the cave seems to be the resting place of something rather "
     "large, as a great deal of branches and leaves are scattered there. The "
     "only exit from this cave is to the north." 
     );
  SetSmell( ([
     "default" : "The cave smells dank and musty, with the faint hint of "
     "rotting meat.",
     ]) );
  SetListen( ([
     "default" : "The sounds of the forest are muted here.",
     ]) );
  SetItems( ([
     ({"floor","ground"}) : "The cave floor is covered in bones.",
     ({"bone", "bones"}) : "The bones appear to come from a number of "
     	 "creatures, including some that appear to be bipedal.",
     ({"branches","leaves","place","bed","branch","leaf"}) : "This appears "
     	 "to be a bed for some sort of very large creature.",
     ({"cave"}) : (:GetLong:),
     ({"exit","opening"}) : "An opening that leads north back into the forest."
    ]) );
  SetItemAdjectives( ([
     "floor" : ({"slanted","cave"}),
     "place" : "resting",
     "area" : ({"dank","poorly","lit"})
     ]) );
  SetInventory( ([
     VAAS_NPC + "bear" : 1,
     ]) );
  SetExits( ([
     "out" : VAAS_ROOM + "forest8",
     ]) );
}