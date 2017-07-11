#include <lib.h>
#include "../gwonish.h"
inherit LIB_POST_OFFICE;

static void create() {
  post_office::create();
  SetClimate("indoors");
  SetTown("Gwonish");
  SetAmbientLight(40);
  SetShort("Gwonish Swamp Postal Service");
  SetLong("The counters are sparse and empty here, waiting only on "
          "someone to need to send or receive their mail.");
  SetExits( ([ 
    "out" : GWONISH_ROOM "gw04",
     ]) );

}


