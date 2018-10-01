#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Temple of the Dark Goddess");
  SetLong(
    "This is the central room of the second level of the Temple "
    "of the Dark Goddess. There is a large stair case leading up. "
    "Looking out of the large, leaded glass windows, the central "
    "courtyard of the church complex can be seen. The blackness "
    "of the mouth of the Abyss yawns open like it could swallow "
    "the world.  There is a shrine to the north."
  );
  SetExits( ([ 
    "west" : G_ROOM + "church1b",
    "east" : G_ROOM + "church3b",
    "up" : G_ROOM + "church2c"
/*
	  "north" : "/realms/zeddicus/thorian/room/grymx_shrine",
*/
  ]) );
}
