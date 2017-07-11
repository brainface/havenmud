//coded by Syra 11/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside Keryth's General Store");
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(55);
  SetLong("This small building houses the only store in Keryth. From its "
          "look, it seems to be a respectable place, but seems slightly "
          "bare.  Shelves line the wall, and a large oil lamp lights the "
          "room from the corner.");
  SetItems( ([
    ({ "large oil lamp", "large oil lantern", "large lamp", "large lantern",
       "oil lamp", "oil lantern", "lantern", "lamp", "corner" }):
       "An oil lantern lights the room brightly.",
    ({ "keryth general store", "general store", "store", "small building",
       "building" }) :
       (:GetLong:),
    ({ "wooden shelves", "shelves", "wall" }) :
       "The wooden shelves that line the wall seem to be perpetually bare."
  ]) );
  SetExits( ([ "out" : K_ROOM + "/road2.c" ]) );
  SetSmell( ([ "default" : "The room smells of burning lamp oil." ]) );
  SetInventory( ([ 
      K_NPC + "/shopkeep" : 1,
      K_NPC + "/armour_equipper" : 1,
      ]) );
}
