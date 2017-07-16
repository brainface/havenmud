/*  A cemetary */
#include <lib.h>
#include <std.h>
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small graveyard");
  SetSmell( ([
     "default" : "The smell of death is in the air.",
      ]) );
  SetListen( ([
      "default" : "The graveyard is silent as the dead.",
      ]) );
  SetLong(
    "This small graveyard seems to be a funeral place "
    "for the goblins. To the west is the main road of the "
    "village. Throughout this area the ground is hewn and "
    "torn and many burn marks streak the ground. "
    "A large black tent sits squarely in the middle of the "
    "field."
    );
  SetItems( ([
   ({ "burn", "burns", "mark", "marks" }) : "These are the marks of pyres "
                                             "long passed.",
   "tent" : "This is the tent of the local shaman.",                                             
    ]) );
  SetExits( ([
      "west" : GOBLIN_ROOM + "m_3",
      ]) );
  SetEnters( ([
    "tent" : GOBLIN_TENT "shaman",
    ]) );
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
  }
