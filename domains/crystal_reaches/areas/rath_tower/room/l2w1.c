#include <lib.h>
#include "../rath.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside the tower");
  SetExits( ([
    "east" : TOWER_R + "/l2r1",
    ]) );
  SetAmbientLight(40);
  SetLong("This are the private quarters of Rath Khan, Emperor of the "
         "World. His room is fairly sparse, with few if any decorations "
         "about the room. Along the west wall is a window which looks "
         "out and over the world. Old rotten tapestries still line the "
         "walls in a pale and faded glory.");
  SetItems( ([
    "window" : "The window overlooks the world.",
    ({ "tapestry", "tapestries" }) : "These tapestries are rotted to the point "
                                     "of threadbare. No details can be made out.",
    ]) );
  SetSmell( ([
    "default" : "The stench of rotted tapestries and dust taints the air.",
    ]) );
  SetListen( ([
    "default" : "It is quiet, almost contemplative, here.",
    ]) );
  SetInventory( ([
      TOWER_N + "/rath" : 1,
    ]) );
 }
