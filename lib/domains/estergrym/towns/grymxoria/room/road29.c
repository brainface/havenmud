#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("crusade court");
  SetLong(
    "This is near the edge of the city's merchants quarter. "
    "Crusade court ends here. Off to the east a little way "
    "the city wall can be seen and, beyond that, darkness."
  );
  SetInventory( ([
    G_NPC + "guard" : 1 
  ]) );
  SetExits( ([ 
    "west" : G_ROOM + "road28"
  ]) );
}

