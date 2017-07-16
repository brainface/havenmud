#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetLong("wheat fields");
    SetDomain("Crystal Reaches");
    SetShort("wheat fields");
    SetLong(
      "A small mining village is to the east, but here " 
      "wheat fields have been cultivated and farmed over the "
      "many years by farmers. Waves move across the "
      "wheat as the breeze blows. An occasional house is "
      "within viewing distance, but nothing other than "
      "that and the wheat can be seen."
    );
    SetItems( ([
      "village"  :
      "A bunch of houses that belong to miners is to the east.",
      "wheat"  :
      "Golden wheat waves gently in the breeze.",
      ({"houses", "house"})  :
      "The occasional house that belongs to a farmer can be seen "
      "on the hills.",
      ({"wave", "waves"})  :
      "Waves made by the wheat moving in the wind go across the "
      "fields.",
      ({"fields", "field"})  :
      "Vast fields of wheat wave gently in the breeze and can be seen "
      "expanding out to the west.",
    ]) );
    SetItemAdjectives( ([
      "village"  :  ({"small", "mining"}),  
      "wheat"    :  ({"golden", "waving"}),
      "wave"    :  "small",
      "field"    :  ({"vast", "wheat"}),
      "houses"    :  ({"farming", "distant"}),
    ]) );
    SetInventory(([
       NPCS + "/farmer" : 1 
    ]));
    SetSmell( ([
      "default"  :  "The scent of tilled earth is about."
    ]) );
    SetListen( ([
      "default"  :  "Wheat whispers in the wind.",
    ]) );
    SetExits( ([
      "east"  :  ROOMS + "/minetown.c",
      "west"  :  ROOMS + "/field2.c",
    ]) );
}
