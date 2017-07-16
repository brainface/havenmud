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
    "This is the inner sanctum of the clerics of Saahagoth.  "
    "The black stone walls are hung with large tapestries. "
    "There are stone benches lining the walls, and a small "
    "fountain of water piped directly from the pure and holy "
    "Blood River."
  );
  SetItems( ([
    "tapestries" : "Large, rich tapestries depicting some of the "
    "many triumphs of the Nosferatu in purifying the world.",
    ({ "bench", "benches" }) : "Benches carved of black marble "
    "line the walls",
    "fountain" : "A small stone fountain of a simple design. "
    "The red water of the pure and holy blood river flows into a "
    "basin, and then back through a pipe to the river."
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([ 
    "east" : G_ROOM + "church2c" 
  ]) );
}

