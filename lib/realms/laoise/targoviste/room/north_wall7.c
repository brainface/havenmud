// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetDayLight(-20);
  SetTown("Targoviste");
  SetShort("the outer bailey of Targoviste");
  SetLong(
    "Southwest of here sits a long low building, which is "
    "nestled up against the wall of the inner keep. The "
    "structure continues to the west and south, wrapping "
    "about the exterior of the keep. Behind the building rises "
    "the inner keep of Targoviste, within which the spires of "
    "the cathedral of Aberach can be seen clawing skyward. "
    "To the west and southeast of here the inner bailey "
    "continues, paved with a black stone which is burnished "
    "to a slight sheen."
  );
  SetItems( ([ 
    ({ "building", "inn", "tavern" }) :
    "A puff of smoke wafts "
    "upwards from a chimney on the roof of this building, "
    "streaming away as the wind pulls it to the southwest. ",


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Various sounds come from the building to the "
    "southwest.",
  ]) );
  SetSmell( ([
    "default" : "The smell of cooking drifts from the building to "
    "the southwest.",
  ]) );
  SetExits( ([ 
    "west" : TARG_ROOM "north_wall6",
    "southeast" : TARG_ROOM "east_wall1",
  ]) );
}
