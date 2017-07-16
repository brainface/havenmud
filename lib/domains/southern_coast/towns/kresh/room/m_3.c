#include <lib.h>
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a fork in the path");
  SetLong(
    "The path splits here, leading to the southeast and the "
    "southwest.  In both directions there are several tents "
    "which obviously hold the life of the village, and either "
    "direction gives off waves of noise and life. There is a tent "
    "here with a small sign on it."
    );
  SetItems( ([
     "tent" : "The tent has a small hole in the top letting smoke out.",
     "sign" : "The sign has pictures of mugs and a drumstick.",
    ]) );
  SetEnters( ([
      "tent" : GOBLIN_TENT + "inn",
      ]) );
  SetRead("sign", "The sign has only pictures on it.");
  SetSmell( ([
     "default" : "The village smells of rotting food and offal.",
      ]) );
  SetListen( ([
      "default" : "The sounds of the village surround you.",
      ]) );
  SetExits( ([
    "southeast" : GOBLIN_ROOM + "m_5",
    "east"      : GOBLIN_ROOM + "cem",
    "southwest" : GOBLIN_ROOM + "m_4",
    "north"     : GOBLIN_ROOM + "m_2",
    ]) );
  SetInventory( ([
      GOBLIN_NPC + "karkaradon" : 1,
      ]) );
  }
