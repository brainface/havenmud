/* testing room*/
#include <lib.h>

// mikes includes dir
#include "../mahk.h"

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  room::create();

  SetClimate("temperate");
  SetAmbientLight(30); 
  SetShort("a path less traveled by");
  SetLong(
    "The path ends here at a barren plain"
  ); 

  SetItems( ([
    ({"ground","distance"}) :
      (: GetLong :),
    ({"plain","clay","barren plain"}):
      "The plain is void of any plant or animal life. The topsoil has long since washed away leaving hard clay behind",
  ]) );

  SetListen( ([
    "default" : "Wolves howl in the distance",
  ]) );

  SetSmell( ([
    "default" : "For some reason, it smells like turpentine.",
  ]) );

  SetInventory( ([
  ]) );

  SetExits( ([
    "north" :  MAHK_ROOM "path04.c",
  ]) );

 
}
