#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("exile avenue");
  SetLong(
    "Near the edge of the rogues quarter of Grymxoria. "
    "Exile avenue comes to an end against the wall of the "
    "cavern here. Exile avenue, named both after the event "
    "in Nosferatu history and after its denizens, leads off "
    "to the east."
  );
  SetExits( ([ 
    "east" : G_ROOM + "road4"
  ]) );
  SetInventory( ([
    G_NPC + "/guard" : 1,
    G_NPC + "/crier" : 2,
  ])  );
}

