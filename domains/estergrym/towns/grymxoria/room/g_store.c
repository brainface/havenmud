#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("kintara's House of Bargains");
  SetLong(
    "Kintara's shop defines organized "
    "chaos. Everything seems thrown about at random, yet "
    "items of the same general nature seem to gather in the same "
    "area."
  );
  SetInventory( ([
    G_NPC "kintara" : 1,
  ]) );
  SetExits( ([ 
    "out" : G_ROOM + "road22" 
  ]) );
}

