#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a shadowy shop");
  SetExits( ([
    "south" : ROME_ROOM "guild1",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetLong("A small candle lights the room from on top of a large counter. The walls "
          "are completely bare of anything except for the shadows created by the "
          "candle light.");
  SetItems( ([
    ({ "candle" }) : "The small candle is the only light "
    "source in the room.",
    ({ "walls" }) : "Dancing shadows cover the walls making it impossible to tell what "
       "is on the walls.",
    ({ "shadows" }) : "The shadows flicker across the walls constantly moving and always "
    "changing.",  
    ({ "counter" }) : "A small candle sits ontop of the counter. The counter itself is "
    "simple and has nothing remarkable about it.", 
    ]) );
  SetItemAdjectives( ([
    "candle" : ({ "small" }),
    "tree" :  ({ "oak", "large" }),
   ]) );
  SetInventory( ([
     ROME_NPC "rmerchant" : 1,
    ]) );
  SetSmell( ([
    "default" : "The room smells of smoke and salt.",
    ]) );
  SetListen( ([
    "default" : "The room is silent.",
    ]) );
}

