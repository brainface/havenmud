//Illura@haven
//b6
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
    "north" : OIL_ROOM "/b5",
    "south" : OIL_ROOM "/b7",
    "west" : OIL_ROOM "/a6",
    "east" : OIL_ROOM "/c6",
  ]) );
  SetItems( ([
    ({"oil", "sand", "sands"}) : "The oil ocean is composed of shifting dark sand and swirling oils, layered with water from the true ocean to the far west.",
    ({"spire", "spires", "shale"}) : "The shale spires shoot out of the oil. They are gray with a translucent sheen, and quite sharp. Perhaps some ancient upheaval brought them out from under the surface.",
    ({"bitumen"}) : "The black mineral is caked and rather sticky, but a more comfortable surface than the slippery oil, whose depths are unfathomable.",
    ({"hole", "holes"}) : "The steam vents trickle out, you guessed it, steam. It stinks."
  ]) );
  SetItemAdjectives( ([
    "bitumen" : ({"cakey"}),
    "oil" : ({"loose"}),
    "hole" : ({"steam"})
  ]) );
  SetInventory( ([
    OIL_NPC + "lurker" : 3,
  ]) );
  SetListen( ([
    "default" : "There is a hissing noise from the steam vents.",
  ]) );
  SetSmell( ([
    "default" : "The fetid air escaping from the vents is noxious.",
  ]) );
}
