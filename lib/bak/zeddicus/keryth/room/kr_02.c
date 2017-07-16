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
    ({ "ground" }) : "Snow covered dirt!  Yes!"
  ]) );

  SetExits( ([
    "north" : K_ROOM "main_01",
    "south" : K_ROOM "kr_01"
  ]) );
}
