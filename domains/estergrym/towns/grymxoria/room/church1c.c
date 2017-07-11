#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Church of Aberach");
  SetLong(
    "This is the inner sanctum of the clerics of Aberach. "
    "The black stone walls are hung with large tapestries. "
    "There are stone benches lining the walls, and a small "
    "fountain of water piped directly from the pure and holy "
    "Blood River."
  );
  SetItems( ([
    ({ "tapestries" }) : "Large, rich tapestries depicting some of the "
    "many triumphs of the Nosferatu in purifying the world.",
    ({ "bench", "benches" }) : "Benches carved of black marble "
    "line the walls",
  ]) );
  SetInventory( ([
    G_OBJ + "cathedral_fountain" : 1,
  ]) );
  SetExits( ([ 
    "east" : G_ROOM + "church2c" 
  ]) );
}
