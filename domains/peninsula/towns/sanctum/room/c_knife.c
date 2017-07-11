#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Sanctum Colosseum");
  SetExits( ([
    "north" : ROME_ROOM "colosseum",
    "east" : ROME_ROOM "c_hack",
    "west" : ROME_ROOM "c_pierce",
    "northwest" : ROME_ROOM "c_slash",
    "northeast" : ROME_ROOM "c_pole",
    ]) );
}
