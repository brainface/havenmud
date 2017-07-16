#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("abyss lane");
  SetLong(
    "At the edge of the city's business quarter. Abyss lane, "
    "named after the huge black pit that it passes, ends against "
    "the city wall here. Beyond only darkness can be seen. The "
    "Grymxoria bank can be seen to the east. While to the south "
    "the huge Grymxoria arena looms up."
  );
  SetItems( ([
    ({ "arena", "grymxoria arena" }) : "A huge circular building "
    "made of black stone blocks."]) );
  SetListen( ([
    "default" : "The sound of cheering, booing, and battle comes "
    "from the arena"
  ]) );
  SetExits( ([ 
    "east" : G_ROOM + "road13"
  ]) );
  SetEnters( ([ 
    "arena" : G_ROOM + "arena2" 
  ]) );
  SetInventory( ([
    G_NPC + "guard" : 1,
    G_NPC + "crier" : 1,
  ])  );
}

