//Illura@haven
//b4
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
    "north" : OIL_ROOM "/b3",
    "south" : OIL_ROOM "/b5",
    "west" : OIL_ROOM "/a4",
    "east" : OIL_ROOM "/c4",
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
    OIL_NPC + "creature" : 4,
  ]) );
  SetListen( ([
    "default" : "There is a hissing noise from the steam vents.",
  ]) );
  SetSmell( ([
    "default" : "The fetid air escaping from the vents is noxious.",
  ]) );
}
