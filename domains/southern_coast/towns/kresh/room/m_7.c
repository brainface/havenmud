#include <lib.h>
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an end to the path");
  SetLong(
    "The path ends here in front of a large tent. The tent seems to be "
    "some kind of jolly gathering place for the tribe. The grasses extend "
    "to the north, leading back towards the heart of the village. "
    "The grasses are trampled down near the tent, almost as if brawls "
    "sometimes manage to find their way from inside the tent to outside."
    );
  SetItems( ([
     ({ "tent" }) : "The tent is a raucous, poorly built construction which could fall "
                                 "over at any moment.",
      ]) );
  SetEnters( ([
     "tent" : GOBLIN_TENT + "fighter",
      ]) );
  SetSmell( ([
     "default" : "The smell of food and drink comes from the tent.",
      ]) );
  SetListen( ([
      "default" : "Odd sounds come from the tent.",
      ]) );
  SetExits( ([
     "north" : GOBLIN_ROOM + "m_5",
    ]) );
  SetInventory( ([
      GOBLIN_NPC + "slash_medium" : 3,
      GOBLIN_NPC + "medium" : 3,
      GOBLIN_NPC + "little" : 3,
    ]) );
  }
