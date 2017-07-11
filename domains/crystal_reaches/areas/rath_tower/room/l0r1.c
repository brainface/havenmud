#include <lib.h>
#include "../rath.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("in the sublevel of the tower");
  SetExits( ([
    "up" : TOWER_R + "/entrance",
    ]) );
  SetAmbientLight(20);
  SetLong("This dimly lit sub level of the tower is a cold and chilling "
          "part of the tower. Its cracked and dusty walls seem to hide "
          "something of great value, but give no indication of what that "
          "might be.");
  SetSmell( ([
     "default" : "The smell of damp air on dust permiates the air.",
    ]) );
  SetListen( ([
    "default" : "Soft whispers seem to echo from the walls entincing the young.",
    ]) );
  SetItems( ([
    ({ "wall", "walls" }) : "The walls give no indication of their treasure.",
    ]) );
 }
