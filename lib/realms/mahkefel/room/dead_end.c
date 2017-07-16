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
  SetShort("a dead end of a pool.");
  SetLong(
    "Oh fuck this place is whack."
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
    "/domains/innersea/encounters/undead/undeadship" : 1,
    "/domains/innersea/encounters/undead/undeadcaptain" : 1,
  ]) );

  SetExits( ([
    "north" : "deep_end.c",
  ]) );

}

