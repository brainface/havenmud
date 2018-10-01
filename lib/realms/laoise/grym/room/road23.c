#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("crusade court");
  SetLong(
    "At the edge of the city's Merchant Quarter. "
    "Crusade court ends here. Off to the west a little way "
    "the city wall can be seen, and beyond that, darkness. "
    "Crusade court, named after the event in Nosferatu History, "
    "continues to the east."
  );
  SetExits( ([ 
    "east" : G_ROOM + "road24"
  ]) );
}

