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
    "In the edge of the rogues quarter of Grymxoria. "
    "Exile avenue comes to an end against the wall of the "
    "cavern here. Exile avenue, named both after the event "
    "in Nosferatu history and after its denizens, leads off "
    "to the west."
  );
  SetExits( ([
    "west" : G_ROOM + "road8"
  ]) );
}
