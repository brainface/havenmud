#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("crusade court");
  SetLong(
    "This is the heart of Grymxoria's Merchant Quarter. Crusade court, "
    "named after the event in Nosferatu history, "
    "extends off to the east and meets with Blood River road to "
    "the west."
  );
  SetExits( ([ 
    "west" : G_ROOM + "road26",
    "east" : G_ROOM + "road28" 
  ]) );
}
