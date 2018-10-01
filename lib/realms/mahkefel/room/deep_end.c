/* testing room*/
#include <lib.h>

// mikes includes dir

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  room::create();


  SetClimate("temperate");
  SetAmbientLight(30);
  SetShort("a deep end of a pool.");
  SetLong(
    "The deep end of the pool is ridiciously deep. Entire ships could fit into it without beaching."
  );
  SetProperty("ocean", 1);
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
    "north" : "kiddy_pool.c",
    "south" : "dead_end.c",
  ]) );

}

