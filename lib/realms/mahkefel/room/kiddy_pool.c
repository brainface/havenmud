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
  SetShort("a kiddy pool in a featureless white room.");
  SetLong(
    "This kiddy pool isn't very deep. The deep end stretches out to the south."
  );
  SetProperty("coastal", 1);
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
    "/domains/innersea/encounters/undead/undeadship" : 1,
  ]) );

  SetExits( ([
    "north" : "../workroom.c",
"south" : "deep_end.c",
  ]) );

}

