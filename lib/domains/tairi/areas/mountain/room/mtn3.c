//Selket@Haven
//2006

#include <lib.h>
#include "../mtn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("on a steep path up the side of Shatadru Mountain");
  SetLong(
    "Here near the base of Shatadru Mountain, the wind blows "
    "coolly across a path that leads along the steep, nearly "
    "vertical slope of the mountain. Delicate plants cling "
    "into the crags and crevices, bringing life to this "
    "otherwise desolate place. "
  );
  SetItems( ([
    ({ "path", "slope" }) : 
    "The path winds sharply up the face of the mountain. ",
    ({ "crag", "crags", "crevice", "crevices" }) : 
    "Shallow niches in the rock that makes up the mountain "
    "are stuffed with plants. ",
    ({ "plants", "plant" }) :
    "The plants have tiny green leaves and tinier flowers. ",
  ]) );
  SetExits( ([
    "up" : MTN_ROOM "/mtn4",
    "down" : MTN_ROOM "/mtn2",
  ]) );
  SetInventory( ([ 
    MTN_NPC "/goat1" : 1,
  ]) );
}
