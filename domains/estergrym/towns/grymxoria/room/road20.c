#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("abyss lane");
  SetLong(
    "At the edge of the city's business quarter. "
    "Abyss lane, named after the huge black pit that it passes, "
    "ends against the city wall here. Beyond only "
    "darkness can be seen. The Grymxoria City Post Office can "
    "be seen to the west. To the south, the Grymxoria library "
    "can be seen, its gothic spires looming up into the air."
  );
  SetItems( ([
    ({ "library" }) : "The Grymxoria library. It is a large stone "
    "building of gothic construction. Its tall spires loom "
    "high up into the air." 
  ]) );
  SetInventory( ([
    G_NPC + "guard" : 1 
  ]) );
  SetExits( ([ 
    "west" : G_ROOM + "road19"
  ]) );
  SetEnters( ([ 
    "library" : G_ROOM + "library1a"
  ]) );
}

