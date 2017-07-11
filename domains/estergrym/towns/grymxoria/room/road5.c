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
    "In the rogues quarter of Grymxoria. Exile avenue, "
    "named both after the event in Nosferatu history and "
    "after its denizens, leads off to the west and meets up "
    "with Blood River road to the east."
  );
  SetExits( ([ 
    "west" : G_ROOM + "road4",
    "east" : G_ROOM + "road6"
  ]) );
}
