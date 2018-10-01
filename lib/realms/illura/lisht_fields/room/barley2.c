//Illura@haven
//Barley2
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../fields.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("in the wide barley fields");
  SetLong(
    "Tall, golden sheaves of barley grow here in swaying "
    "rows. The tall stalks of grain will someday become "
    "delicious beers and breadstuffs, but for now are content "
    "to be tended in the drying sun. There are small canals "
    "feeding water into the soil here, which lead eastward "
    "to a larger main and the road."
  );
  SetExits( ([
    "east" : FIELDS_ROOM "road1",
    "south" : FIELDS_ROOM "onion2",
    "west" : FIELDS_ROOM "barley1"
  ]) );
  SetItems( ([
    ({"sheaves", "sheaf", "barley", "stalks", "stalk", "grain"}) : "The yellowish barley plants grow in tall rows.",
    ({"row", "rows"}) : "Carefully tended rows stretch across the field in straight, parallel lines.",
    ({"canal", "canals", "water" }) : "The dark canals are full of silt and murky river water.",
    "soil" : "The soil is mostly black silt from the riverbed.",
    ({"main", "road"}) : "Following the canals will lead back to the main canal and the road."
  ]) );
  SetItemAdjectives( ([
    "sheaves" : ({"tall", "golden"}),
    "row" : "swaying",
    "canal" : "small",
    "main" : "larger"
  ]) );
  SetInventory( ([
    FIELDS_NPC + "gnollworkerf" : 1,
    FIELDS_NPC + "elfworker" : 3,
    FIELDS_NPC + "overseer" : 2,
  ]) );
  SetListen( ([
    "default" : "The wind rustles the barley with a crackling sound.",
  ]) );
  SetSmell( ([
    "default" : "The air is kiln-hot and smells of grains.",
  ]) );
}
