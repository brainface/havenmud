#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetShort("the Thirsty Viking");
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetLong("Long description.");

  SetExits( ([ "out" : K_ROOM "main_01" ]) );

  SetListen( ([
    "default" : "The hustle and bustle of business fill the air."
  ]) );
}
