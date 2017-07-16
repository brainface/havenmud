//Illura@haven
//h6
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("the great oil ocean");
  SetLong(
    "The oil ocean extends in all directions from here, spotted "
    "sporadically with spires of shale. Cakey bitumen crunches "
    "under your feet, but with careful strides, you won't sink into "
    "the loose oil sands beneath. Steam holes burst through "
    "the ground every few feet, ventilating the ooze."
  );
  SetExits( ([
    "north" : OIL_ROOM "/h5",
    "west" : OIL_ROOM "/g6",
  ]) );
  SetItems( ([
    ({"ocean"}) : (: GetLong :),
    ({"oil", "sand", "sands", "surface", "ground"}) : 
    "The oil ocean is composed of shifting dark sand and swirling oils, "
    "layered with water from the true ocean to the far west.",
    ({"spire", "spires", "shale", "sheen"}) : 
    "The shale spires shoot out of the oil. They are grey with a "
    "translucent sheen, and quite sharp. Perhaps some ancient upheaval "
    "brought them out from under the surface.",
    ({"bitumen", "mineral"}) : 
    "The black mineral is caked and rather sticky, but a more "
    "comfortable surface than the slippery oil, whose depths "
    "are unfathomable.",
    ({"hole", "holes"}) : 
    "The steam vents trickle out, you guessed it, steam. It stinks."
  ]) );
  SetItemAdjectives( ([
    "ocean" : ({"great", "oil", "true"}),
    "bitumen" : ({"cakey", "black", "caked", "sticky"}),
    "oil" : ({"loose", "shifting", "dark", "swirling", "grey", "translucent",
              "slippery"}),
    "hole" : ({"steam"}),
    "spire" : ({"shale"})
  ]) );
  SetInventory( ([
    OIL_NPC + "octopus" : 3,
  ]) );
  SetListen( ([
    "default" : "There is a hissing noise from the steam vents.",
  ]) );
  SetSmell( ([
    "default" : "The fetid air escaping from the vents is noxious.",
  ]) );
}
