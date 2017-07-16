#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a dilapidated building");
  SetAmbientLight(30);
  SetClimate("indoors");
  SetExits( ([
     "out" : P_ROOM + "/wharfy",
    ]) );
  SetLong("This pathetic building is some kind of squatter's home. "
          "Trash litters the floor seems to only be moved aside for "
          "minor living convienence. On the walls of this room are "
          "paintings of far away places.");
  SetListen( ([
      "default" : "The room is quiet and peaceful.",
     ]) );
  SetSmell( ([
     "default" : "The room smells of rotting trash.",
     ]) );
  SetItems( ([
     "trash" : "Trash piles litter the floor randomly.",
     ({ "painting", "paintings" }) : "These cheap pictures are of "
                  "places far away.",
    ]) );
  SetInventory( ([
     P_NPC + "/sage" : 1,
    ]) );
}
