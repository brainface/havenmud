#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("on the Outskirts of Keryth");
  SetLong("Long description.");

  SetItems( ([
    ({ "ground" })  : "Snow covered dirt!  Yes!"
  ]) );

  SetExits( ([
    "east"      : K_ROOM "lakeshore",
    "southwest" : K_ROOM "kr_04"
  ]) );
}
