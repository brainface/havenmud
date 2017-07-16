// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_POST_OFFICE;

static void create() {
  post_office::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetTown("Dalnairn");
  SetShort("in the dalnairn post office");
  SetLong("This is the post office that serves the city of Dalnairn. "
    "From here, citizens may send and receive their mail by typing <mail>. "
    "Once in, simply follow the instructions."
  );
  SetItems( ([
  ({ "office" }) : (: GetLong :),    
  ]) );
  SetItemAdjectives( ([
    "office" : ({ "post" }),
  ]) );  
  SetExits( ([
    "out" : DAL_ROOM "road4",
  ]) );  
}
