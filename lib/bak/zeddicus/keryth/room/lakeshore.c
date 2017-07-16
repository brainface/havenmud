#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("on the Shore of a Lake");
  SetLong("Long description.");

  SetItems( ([
    ({ "water" })  : "Water!  Yes!"
  ]) );

  SetExits( ([
    "west" : K_ROOM "outskirt"
  ]) );
}
