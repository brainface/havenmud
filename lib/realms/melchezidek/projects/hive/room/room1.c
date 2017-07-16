#include <lib.h>
#include <std.h>
#include "../hive.h"
inherit LIB_ROOM;

static void create() {
        ::create();
        SetClimate("underground");
        SetAmbientLight(45);
        SetShort("below a sinkhole in the desert");
        SetLong("Sand cascades down from the sides of the sinkhole above."
                " It pools on the floor on top of the thickly packed sand"
                " that composes the floor here. The light seeping in through"
                " the hole illuminates the area, which is essentially a sandy"
                " cave, and reveals an exit to the south."
          );
        SetItems( ([
              "sand" : "The sand falling from the hole is very small and a"
                       " light golden color.",
              "floor": "Tightly packed sand composes the floor. It appears to have"
                       " been pressed by a large amount of weight, making an"
                       " almost even surface to walk upon.",
              "hole" : "The hole above is quite large in diameter and around the"
                       " edges small grains of sand cascade down to the floor.",
              "cave" : (: GetLong :),
               ]) );
        SetItemAdjectives( ([
              "sand" : ({ "loose", "golden", "small" }),
              "floor": ({ "tight", "packed", "tightly packed", "sand", "sandy" }),
              "hole" : ({ "sink", "large", "sandy" }),
               ]) ),    
        SetInventory( ([
            HIVE_OBJ "largecrystal"    : 1,
            ]) );
        SetExits( ([
           "up"    : HIVE_NORTH_EXIT,
           "south" : HIVE_ROOM "room2",
           ]) );
}
