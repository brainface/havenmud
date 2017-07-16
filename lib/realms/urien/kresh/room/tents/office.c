#include <lib.h>
#include "../../goblins.h"

inherit LIB_POST_OFFICE;
 
static void create() {
  post_office::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Kresh");
  SetShort("Kresh's Post Office");
  SetLong("This is the city post office that serves the town of Kresh. "
          "From here, citizens may send and receive their mail by typing "
          "<mail>.  Once in, simply follow the instructions.");
  SetNewsgroups( ({ "ooc", "news.announcements" }) );
  SetExits( ([ "out" : GOBLIN_ROOM + "m_4" ]) );
  }

 

          

