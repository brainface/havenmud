#include <lib.h>
#include "../herm.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("a vault inside the hermitage");
  SetLong("This is a large vault on the south side of"
          " the hermitage. Much like the preceeding room"
          " this room is very simple. A large pentagram"
          " has been drawn upon the floor with candles"
          " placed at the corners.");
  SetItems( ([
          ({ "pentagram", "candles", "candle", "floor" }) :
           "A large pentagram has been drawn upon the"
           " floor with candles placed at the five"
           " points."
          ]) );
  SetSmell( ([
          "default" : "A soft spicy odor resides here",
       ]) );
  SetListen( ([
          "default" : "Only ambient noises from outside"
          " penetrate the silence",
        ]) );
  SetExits( ([
           "north" : HERM_ROOM "herm1",
        ]) );
  SetInventory( ([
           HERM_NPC "hermit" : 1,
        ]) );
}
