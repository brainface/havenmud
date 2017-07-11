//Illura@haven
//e8
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
    "Here the oil ocean juts up and down, where underground "
    "upheaval has lifted shale and sandstone above the surface. "
    "The shale is a silvery color, but the rough surface of the "
    "sandstone, though weathered, is mostly covered by "
    "rusty oil. The walking here is rough and rocky in most "
    "directions, and travel further south is limited by the slippery "
    "shale ground cover. In the south the faint outline of the "
    "Barian Jungle makes a green haze on the horizon."
  );
  SetExits( ([
    "north" : OIL_ROOM "/e7",
    "west" : OIL_ROOM "/d8",
  ]) );
  SetItems( ([
    ({"oils", "oil", "ocean"}) : "The Oil Ocean extends in all directions, made of tar sands and black substances that swirl and shimmer and ooze mysteriously.",
    ({"shale", "sandstone"}) : "Oil shale and sandstone from deep underground have been thrust upward by ancient earthquakes. The shale is a silvery gray, slippery enough that most of the oil has dripped off of it in time. The sandstone is tinted a rusty, dried blood color.",
    ({"jungle"}) : "The Barian Jungle is far off to the south. You would never make it in this terrain."
  ]) );
  SetItemAdjectives( ([
    "oil" : ({"rusty"}),
    "shale" : ({"slippery"})
  ]) );
  SetInventory( ([
    OIL_NPC + "lurker" : 4,
  ]) );
  SetListen( ([
    "default" : "The rocks crunch and squeal unctuously underneath your feet as they rub together."
  ]) );
  SetSmell( ([
    "default" : "You swear you can smell the rainforest at this distance.",
  ]) );
}
