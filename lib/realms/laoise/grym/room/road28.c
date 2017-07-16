#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("crusade court");
  SetLong(
    "This is the heart of the city's Merchant Quarter. "
    "Crusade Court, named after the event in Nosferatu history, "
    "extends off to the east and west."
  );
  SetExits( ([ 
    "west" : G_ROOM + "road27",
    "east" : G_ROOM + "road29" 
  ]) );
}
