//Illura@haven
//f5
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
    "In every direction, the murky oil sands extend, dotted with "
    "irregular stalagmites of sharp oil shale, like some kind of "
    "otherworldly coral reef. Saline water has turned the bitumen "
    "sludge a thousand shades of brown and rust, also making "
    "travelling here a slow process."
  );
  SetExits( ([
    "north" : OIL_ROOM "/f4",
    "south" : OIL_ROOM "/f6",
    "west" : OIL_ROOM "/e5",
    "east" : OIL_ROOM "/g5",
  ]) );
  SetItems( ([
    ({"oil", "sand", "sands"}) : "The oil ocean is composed of shifting dark sand and swirling oils, layered with water from the true ocean to the far west.",
    ({"stalagmite", "stalagmites", "shale"}) : "Shale stalagmites and spires thrust up through the sands, very sharp. They are the only scenery to be had.",
    ({"water"}) : "Saline water from the far away sea mixes with the oil sludge.",
    ({"sludge"}) : "The sludge is thick. You would not want to sink into it."
  ]) );
  SetItemAdjectives( ([
    "oil" : ({"murky"}),
    "stalagmite" : ({"sharp", "irregular"}),
    "water" : "saline",
  ]) );
  SetInventory( ([
    OIL_NPC + "octopus" : 3,
  ]) );
  SetListen( ([
    "default" : "You can hear the oil popping and shifting in the ground.",
  ]) );
  SetSmell( ([
    "default" : "The air smells of burnt tar and insipid water.",
  ]) );
}
