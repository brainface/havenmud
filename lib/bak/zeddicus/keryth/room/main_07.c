#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("Cemetery and Main");
  SetLong("Long description.");

  SetItems( ([
    ({ "temple" }) : "A temple!  Yes!"
  ]) );

  SetExits( ([
    "east"      : K_ROOM "main_06",
    "north"     : K_ROOM "cr_01",
  ]) );

  SetEnters( ([
    "temple" : K_ROOM "temple"
  ]) );
}
