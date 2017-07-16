#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("exile avenue");
  SetLong(
    "In the heart rogues quarter of Grymxoria. Exile "
    "avenue, named both after the event in Nosferatu history "
    "and after its denizens, leads off to the east and west. The "
    "cavern wall can be dimly seen to the east."
  );
  SetExits( ([ 
    "east" : G_ROOM + "road9",
    "west" : G_ROOM + "road7" 
  ]) );
}
