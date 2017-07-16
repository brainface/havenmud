#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("the Keryth Cemetery");
  SetLong("Long description.");

  SetItems( ([
    ({ "ground" }) : "Dirt with dead people!  Yes!"
  ]) );

  SetExits( ([
    "southeast" : K_ROOM "cemetery1",
    "east"      : K_ROOM "cemetery2",
    "south"     : K_ROOM "cemetery4"
  ]) );
}
