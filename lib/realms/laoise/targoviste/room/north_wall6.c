
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
    "South of here is a long, low building which continues to the "
    "southeast. Nestled up against the wall of the inner keep, this "
    "building forms a somewhat triangular shape as it juts outward. "
    "From its chimney swirls a column of smoke, trailing away to the "
    "southwest as the wind draws it. Above the doorway is a sign depicting "
    "a mug with froth rising from its top, sitting next to a plate heaped "
    "high with food. To the west and east the outer bailey continues, "
    "its paving of polished black marble stretching in to the distance."
  );
  SetItems( ([ 
    ({ "bar", "tavern", "building" }) : "The local",
  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A rumble of voices comes from the building to "
    "the south.",
  ]) );
  SetSmell( ([
    "default" : "The smell of cooking wafts through the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "north_wall7",
    "west" : TARG_ROOM "north_wall5",
  ]) );
  SetEnters( ([
    "bar" : TARG_ROOM "bar3",
  ]) );
}
