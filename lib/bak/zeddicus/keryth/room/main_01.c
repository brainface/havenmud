#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("Keryth and Main");
  SetLong("Long description.");

  SetItems( ([
    ({ "tavern" }) : "A tavern!  Yes!"
  ]) );

  SetExits( ([
    "north" : K_ROOM "kr_03",
    "south" : K_ROOM "kr_02",
    "west"  : K_ROOM "main_02"
  ]) );

  SetEnters( ([
    "tavern" : K_ROOM "tavern"
  ]) );
}
