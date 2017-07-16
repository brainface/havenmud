#include <lib.h>
#include "../wood.h"

inherit LIB_POST_OFFICE;
 
static void create() {
  post_office::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Havenwood");
  SetShort("Havenwood Post Office");
  SetLong("This is the city post office that serves the Havenwood. "
          "From here, citizens may send and receive their mail by typing "
          "<mail>.  Once in, simply follow the instructions.");
  SetNewsgroups( ({ "ooc", "news.announcements" }) );
  SetExits( ([ "east" : HWD_ROOM + "/gelf5" ]) );
}

 

          

