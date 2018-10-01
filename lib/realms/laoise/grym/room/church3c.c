#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Church of Saahagoth");
  SetLong(
    "This is the private chapel for the clerics of Saahagoth.  "
    "There is a small altar at the end of the room. "
    "On one wall is a board for the clerics of Saahagoth "
    "to discuss ideas for new prayers."
  );
  SetItems( ([
    "altar" : "A small black stone altar with several religious "
    "items and small offerings on it."]) );
  SetInventory( ([
   ]) );
  SetExits( ([ 
    "west" : G_ROOM + "church2c" 
  ]) );
}
