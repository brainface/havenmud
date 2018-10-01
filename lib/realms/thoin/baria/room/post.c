#include <lib.h>
#include "../jungle.h"

inherit LIB_POST_OFFICE;
 
static void create() {
  post_office::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Baria");
  SetShort("Baria's Post Office");
  SetLong("This is the city post office that serves the village of Baria. \n"
          "From here, citizens may send and receive their mail by typing \n"
          "<mail>.  Once in, simply follow the instructions.");
  SetSmell( ([
     "default" : "The air smells old and stale.",
  ]) );
  SetListen( ([
     "default" : "It is quiet and calm. ",
  ]) );
  SetExits( ([ "out" : BARIA_ROOM + "path8" ]) );
  }
