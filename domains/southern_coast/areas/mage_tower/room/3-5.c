#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetShort("a wide open room");
  SetClimate("indoors");
  SetAmbientLight(25);
  SetExits( ([
    "south" : "3-4",
    ]) );
  SetSmell( ([
    "default" : "The residual smell of burning candles hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "Though it is quiet, occasional whispers echo from "
                "the walls.",
    ]) );
  SetLong("This room is a wide open room obviously used for summonings. "
          "Drawn in the center of the floor is a pentagram surrounded "
          "by candles, which is the only source of illumination. "
          "To the south stands a huge iron door which seems to "
          "protect the room from escaping demons. The walls of the "
          "room are made of a smooth stone which has been carefully "
          "crafted to leave no imperfections.");
  SetItems( ([
    ({ "floor", "pentagram" }) : "The floor is centered with a "
                                 "a large chalked in pentagram. "
                                 "The pentagram is cornered by "
                                 "burning candles.",
    ({ "candle", "candles" }) : "The candles are made of a waxy "
                                "material, however the flames do "
                                "not waver with any breeze.",
    ({ "flame", "flames" }) : "The flames of the candles stoically "
                              "do not quiver in the breeze.",
    ({ "wall", "stone", "walls" }) : "The walls are carefully crafted "
                                     "not to have any imperfections.",
    ]) );
  SetInventory( ([
    TOWER_OBJ "chest" : 1,
    ]) );
  SetDoor("south", TOWER_OBJ "door35");
}

varargs void reset(int count) {
  ::reset(count);
  call_other( TOWER_OBJ "door35", "SetClosed", 1);
  call_other( TOWER_OBJ "door35", "SetLocked", 1);
}
