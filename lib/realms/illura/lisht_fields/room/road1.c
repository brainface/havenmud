//Illura@haven
//Road1
//Oct 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../fields.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("a road through fertile fields");
  SetLong(
    "The black alluvial soil of this tramped road runs north "
    "and south alongside a shallow irrigation ditch leading "
    "water away from the River Itro to thirsty fields, which "
    "stretch to each horizon. Wild marjoram and garlic sprout "
    "along the banks, due to the lush nature of the soil."
  );
  SetExits( ([
    "west" : FIELDS_ROOM "barley2",
    "south" : FIELDS_ROOM "road2",
    "east" : FIELDS_ROOM "emmer1",
  ]) );
  SetItems( ([
    ({"marjoram", "garlic", "bank", "banks"}) : "Wild plants grow along the dark banks of the canal.",
    ({"ditch", "water" }) : "The dark canals are full of silt and
murky river water.",
    "soil" : "The soil is mostly black silt from the riverbed.",
    "road" : "Following the canals will lead back to the river or further into the fields."
  ]) );
  SetItemAdjectives( ([
    "soil" : ({"black", "lush", "alluvial"}),
    "road" : "tramped",
    "ditch" : ({"shallow", "irrigation"}),
    "marjoram" : "wild",
  ]) );
  SetInventory( ([
    FIELDS_NPC + "irrigationworker" : 1,
  ]) );
  SetListen( ([
    "default" : "Water sloshes against the banks gently.",
  ]) );
  SetSmell( ([
    "default" : "The air smells of fragrant herbs.",
  ]) );
}
