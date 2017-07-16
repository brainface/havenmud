#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetShort("a Small Armoury");
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(55);
  SetLong("Long description.");

  SetItems( ([
    ({ "ground" }) : "Yep.  It's the ground alright."
  ]) );

  SetExits( ([ "out" : K_ROOM + "main_06" ]) );

  SetListen( ([
    "default" : "Sounds!"
  ]) );
}
