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
    "This is the heart of the city's merchants quarter. "
    "Crusade Court, named after the event in Nosferatu history, "
    "extends off to the east and west."
  );
  SetExits( ([ 
    "west" : G_ROOM + "road27",
    "east" : G_ROOM + "road29" 
  ]) );
}
