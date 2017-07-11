#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetClimate("indoors");
  SetProperty("no magic", 1);
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetNewsgroups( ({ "religion.aberach" }) );
  SetShort("the Church of Aberach");
  SetLong(
    "This is the private chapel for the clerics of Aberach.  "
    "There is a small altar at the end of the room. "
    "On one wall is a board for the clerics of grymxoria "
    "to discuss ideas for new prayers."
  );
  SetProperty("no teleport", 1);
  SetItems( ([
    ({ "altar" }) : "A small black stone altar with several religious "
    "items and small offerings on it.",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([ 
    "west" : G_ROOM + "church2c",
  ]) );
}
