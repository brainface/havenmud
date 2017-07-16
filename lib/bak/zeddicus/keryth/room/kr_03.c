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
    ({ "library" })  : "A library!  Yes!",
    ({ "barracks" }) : "A barracks!  Yes!"
  ]) );

  SetExits( ([
    "north" : K_ROOM "kr_04",
    "south" : K_ROOM "main_01"
  ]) );

  SetEnters( ([
    "library"  : K_ROOM "library3",
    "barracks" : K_ROOM "barracks3"
  ]) );
}
