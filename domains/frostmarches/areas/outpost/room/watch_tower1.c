#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside the watch tower");
  SetLong(
    "The ground floor of this tower is made of wooden planks, which is slightly "
    "wet from the snow deposits left by the inquisitors� boots. The ceiling is "
    "as high as the tower itself. A ladder resting against the west wall and "
    "leads up through an opening in the ceiling. The large crates and wooden "
    "barrels have been stuffed into the back of the tower. ");
  SetClimate("indoors");
  SetItems( ([
    ({"floor","plank","planks","ground"}) :
    "The wooden planks provide a little warmth from the frozen ground which "
    "hides beneath it. The floor is slightly wet from the snow deposits left" 
    "by boots of the inquisitors.",
    "tower" : ( :GetLong: ),
    ({"deposits","snow","puddle","water"}) :
    "Small puddles of water lead from the door to the ladder. The water must "
    "be from snow brought in from outside the tower.",
    "ceiling" :
    "The wooden ceiling hangs high above with an opening near the west wall, "
    "which gives access to the top of the tower.",
    ({"opening","ladder"}) :
    "A wooden ladder nailed into the west wall leads up to the opening in "
    "the ceiling allowing access to the next floor.",
    ({"crate","crates","barrel","barrels"}) :
    "Several crates and wooden barrels are stuffed up against the back of the "
    "tower.",
    ({"wall","walls"}) :
    "The wall are made of wood and are unadorned. On the west wall, a ladder "
    "has been nailed to allow access to the opening in the ceiling.",
    ]) );
  SetItemAdjectives(( [
    "floor"    : ({"wooden","wet"}),
    "puddle"   : ({"small","water"}),
    "ceiling"  : ({"wooden"}),
    "wall"     : ({"west"}),
    "ladder"   : ({"wooden","nailed"}),
    "crate"    : ({"wooden","large","wood"}),
    "wall"     : ({"west"}),
    "deposits" : ({"snow"}),
    ]) );
  SetExits( ([
    "out" : OP_ROOM + "staging_area1",
    "up"  : OP_ROOM + "watch_tower2",
    ]) );
  SetSmell( ([
    "default" : 
    "A slight dusty odor lingers in the air.",
    ]) );
  SetListen( ([
    "default" : 
    "Soft whistling can be heard."
    ]) );

}