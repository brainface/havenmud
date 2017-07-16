#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;
 
static void create()
{
  room::create();
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("the Mayor's Office");
  SetLong("Long description.");

  SetExits( ([ 
    "north" : K_ROOM "town_hall"
	]) );
}
