#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("on the Dock");
  SetLong("Long description.");

  SetItems( ([
    ({ "water" })  : "Water!  Yes!"
  ]) );

  SetExits( ([
    "southeast" : K_ROOM "cr_05"
  ]) );
}
