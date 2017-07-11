#include <lib.h>
#include "../path.h"
#include <std.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside a chicken coop");
  SetExits( ([
    "out"  : LLORYK "room/farm3",
    ]) );
  SetLong("The large chicken coop looks like it could hold many chickens. While "
          "a small ramp leads out for the chickens, a small doorway leads back "
          "out. The walls of the coop are made from loosely connected wooden "
          "boards.");
  SetItems( ([
      ({ "coop" }) : 
         (: GetLong :),
      ({ "wall", "walls", "board" }) : 
         "The walls are made from wooden boards. The boards look very old and "
         "rotting in some places.",
   ]) );
  SetItemAdjectives( ([
      "coop" : ({ "chicken", "large" }),
      "board" : ({ "wooden" }),
   ]) );
  SetSmell( ([
    "default" : "Fertilizer and pig stinks up the air.",
    ]) );
  SetListen( ([
    "default" : "The occasional \"moo\" drifts in from afar.",
    ]) );
  SetInventory( ([
    LLORYK "npc/flu_bird" : 5,
    ]) );
  SetFarmingBonus(15);  
}
