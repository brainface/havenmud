#include <lib.h>
#include "../keryth.h"

inherit LIB_POST_OFFICE;
 
static void create()
{
  post_office::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Keryth");
  SetShort("the Keryth Post Office");
  SetLong("Long description.");

  SetExits( ([ 
    "out"  : K_ROOM "main_04",
    "east" : K_ROOM "town_hall"
  ]) );

  SetProperty("no bump", 1);
  SetProperty("no attack", 1);
}
