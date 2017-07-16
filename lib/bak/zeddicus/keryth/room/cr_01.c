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
    ({ "cemetery" }) : "Dead people!  Yes!"
  ]) );

  SetExits( ([
    "north" : K_ROOM "cr_02",
    "south" : K_ROOM "main_07",
    "west"  : K_ROOM "cemetery1"
  ]) );

}
