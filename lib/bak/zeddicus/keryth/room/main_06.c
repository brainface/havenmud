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
    ({ "armoury" })  : "An armoury!  Yes!",
    ({ "barracks" }) : "A barracks!  Yes!"
  ]) );

  SetExits( ([
    "east" : K_ROOM "main_05",
    "west" : K_ROOM "main_07"
  ]) );

  SetEnters( ([
    "armoury"  : K_ROOM "armoury",
    "barracks" : K_ROOM "barracks1"
  ]) );
}
