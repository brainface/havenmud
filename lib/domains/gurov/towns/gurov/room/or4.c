#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "north" : GUROV_ROOM "or5",
    "west"  : GUROV_ROOM "or3",
    ]) );
  SetShort("a curve in the Outer Road");
  SetLong(
    "The Outer Road curves to the north and west here, leading deeper "
    "into the city's various sections.  To the north, the road leads "
    "to the Barracks and Hospital, while back to the west lies the "
    "town gate. The town wall rises up here twenty feet high, its grey "
    "stone a barrier against all enemies. There is a small hovel here which "
    "appears to be a very practical, if unexciting, domecile."
    );
  SetItems( ([
    "wall" : "The normally perfect wall seems to have a crack in it here.",
    "crack" : "The crack is fairly small and not worth noting.",
    ({ "hovel", "domecile" }) : "This small hovel is the home of Baba Yaga, the Practical Witch.",
    ]) );
  SetSmell("The road smells of horse droppings.");
  SetListen("The curve is quiet and serene.");
  SetEnters( ([
    "hovel" : GUROV_ROOM "practical",
    ]) );
}