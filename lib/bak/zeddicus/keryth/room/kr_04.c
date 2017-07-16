#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("Keryth Road");
  SetLong("Long description.");

  SetItems( ([
    ({ "hut" })  : "A hut!  Yes!"
  ]) );

  SetItemAdjectives( ([
    "hut" : ({ "healer" })
  ]) );

  SetExits( ([
    "northeast" : K_ROOM "outskirt",
    "south"     : K_ROOM "kr_03"
  ]) );

  SetEnters( ([
    "hut"  : K_ROOM "healer_hut"
  ]) );
}
