#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("Main Street");
  SetLong("Long description.");

  SetItems( ([
    ({ "barracks" }) : "A barracks!  Yes!"
  ]) );

  SetExits( ([
    "east" : K_ROOM "main_01",
    "west" : K_ROOM "main_03"
  ]) );

  SetEnters( ([
    "barracks" : K_ROOM "barracks2"
  ]) );
}
