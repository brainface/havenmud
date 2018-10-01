#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetExits( ([
    "south" : G_ROOM +"library2b",
    "down" : G_ROOM + "library1a",
  ]) );
  SetShort("grymxoria Mage common room");
  SetLong(
    "This is the common room for the mages of Grymxoria. "
    "There is a cozy fire burning in a fireplace, and there "
    "are several comfortable couches scattered about the "
    "room. On one wall is the mage discussion board."
  );
  SetSmell( ([
    "default" : "The air has the faint scent of burning wood." 
  ]) );
  SetListen( ([ 
    "default" : "The fire cracks and pops warmly."
  ]) );
  SetItems( ([
    ({ "fire", "fireplace" }) : "A cozy fire burning in a "
    "stone fireplace.",
    ({ "couch", "couches" }) : "Comfy, slightly worn, cushioned "
    "couches.",
    ]) );
  SetInventory( ([
  ]) );
}

