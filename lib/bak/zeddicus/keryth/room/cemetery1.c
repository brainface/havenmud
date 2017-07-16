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
    "west"      : K_ROOM "cemetery4",
    "east"      : K_ROOM "cr_01",
    "north"     : K_ROOM "cemetery2",
    "northwest" : K_ROOM "cemetery3"
  ]) );
}
