#include <lib.h>
#include "../path.h"
inherit LIB_POST_OFFICE;

static void create() {
  post_office::create();
  SetClimate("indoors");
  SetTown("Lloryk");
  SetAmbientLight(40);
  SetShort("Shire Postal Service");
  SetLong("The counters are sparse and empty here, waiting only on "
          "someone to need to send or receive their mail.");
  SetExits( ([ 
    "out" : LLORYK + "room/uh4",
     ]) );

}


