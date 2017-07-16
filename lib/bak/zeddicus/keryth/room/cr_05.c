#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("Cemetery Road");
  SetLong("Long description.");

  SetItems( ([
    ({ "ground" }) : "Dirt!  Yes!"
  ]) );

  SetExits( ([
    "northwest"     : K_ROOM "dock",
    "south"         : K_ROOM "cr_04"
  ]) );
}
