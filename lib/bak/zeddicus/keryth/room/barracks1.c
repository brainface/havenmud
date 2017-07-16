#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetShort("a Barracks");
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(45);
  SetLong("Long description.");

  SetItems( ([
    ({ "ground" }) : "Yep.  It's the ground alright."
  ]) );

  SetExits( ([ "out" : K_ROOM "main_06" ]) );

  SetListen( ([
    "default" : "Sounds!"
  ]) );
}
