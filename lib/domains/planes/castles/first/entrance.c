/*  A basic entrance room */
#include <lib.h>
#include "../../planes.h"
inherit LIB_ROOM;
#include <setup.h>

int PreExit();

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("the entrance to the castle");
  SetExits( ([
      "out" : FIRST_PLANE + "0,0",
     ]) );
  SetLong("This is the main hall of an abandoned castle. "
          "Many centuries ago, this may have been the castle of "
          "an Arch Devil, but now it seems only to be a dead "
          "area with little to recommend it as a place to visit. "
          "There is a small vortex of torn reality on the wall.");
  SetItems( ([
     "vortex" : "This is a vortex of pure chaos.",
      ]) );
  AddEnter("vortex", DIR_STANDARD_DOMAIN "/room/setup", (: PreExit :) );
}

int PreExit() {
   if(!userp(this_player())) {
      return 0;
   } else return 1;
}
