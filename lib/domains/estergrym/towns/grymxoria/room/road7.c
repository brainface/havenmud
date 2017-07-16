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
    "The heart of the rogues quarter of Grymxoria. Exile "
    "avenue, named both after the event in Nosferatu history "
    "and after its denizens, leads off to the east and meets up "
    "with Blood River road to the west."
  );
  SetExits( ([ 
    "east" : G_ROOM + "road8",
    "west" : G_ROOM + "road6"
  ]) );
  SetInventory( ([
          G_NPC + "citizen" : 1 
  ]) );
}

