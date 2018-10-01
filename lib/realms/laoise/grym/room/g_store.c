#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("Kintara's House of Bargains");
  SetLong(
    "Kintara's shop defines organized chaos. Everything "
    "seems thrown about at random, yet items of the same "
    "general nature seem to gather in the same area."
  );
  SetExits( ([ 
    "out" : G_ROOM + "road22" 
  ]) );
  SetInventory( ([
	G_NPC "kintara" : 1,
  ]) );
}

