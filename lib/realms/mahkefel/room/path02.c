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
    "This featureless path travels on in the distance."
  ); 

  SetItems( ([
    ({"ground","distance"}) :
      (: GetLong :),
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
    "north" :  MAHK_ROOM "path01.c",
    "south" :  MAHK_ROOM "path03.c",
  ]) );

 
}
