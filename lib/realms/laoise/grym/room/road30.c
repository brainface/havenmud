#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("blood River road");
  SetLong(
    "Blood river road comes to an end at a small gate of red "
    "metal. The city wall extends to the east and west. Blood River "
    "road runs off to the north."
  );
  SetExits( ([ 
    "north" : G_ROOM + "road26"
  ]) );
}
