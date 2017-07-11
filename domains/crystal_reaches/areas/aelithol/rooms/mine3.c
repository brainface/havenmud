#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(40);
    SetShort("in a mine");
    SetLong(
      "Timbers have been erected to attempt to hold the earth "
      "up. The stone shows the marks of sharp tools which have "
      "slowly worked away the hillside's stone in the search for "
      "a particular material. Pebbles and dust on the floor have "
      "mixed with the slightly damp floor surface and made a "
      "form of mud. The tunnel continues to the north."
   );
    SetItems( ([
      ({"timbers", "timber"}) :
      "Timbers have been put in place to hold the earth up.",
      ({"torches", "torch", "light"})  :
      "Torches have been lit to illuminate the mine.  They flicker "
      "as air from the interior of the mine rushes by.",
      "stone"  :
      "The stone is a dark, cold and very damp.",
      ({"walls", "wall"})  :
      "The walls of the mine are made from a dark, cold stone that is "
      "very damp.",
      "tunnel"  :
      "The tunnel leads to the north.",
      "earth"  :
      "Some parts of the walls contain earth.  Some of it has "
      "fallen into the floor to contribute to the mud.",
      ({"pebbles", "pebble", "dust", "mud", "floor", "surface"})  :
      "Pebbles and dust have mixed with the damp surface of the "
      "floor to form mud.",
      ({"mark", "marks"})  :
      "Mining implements that carved the tunnel left marks "
      "on the walls.",
    ]) );
    SetItemAdjectives( ([
      "torches"    :  "lit",
      "stone"  :  ({"hillside", "damp", "dark", "cold"}),
      "light"    :  "torch",
      "walls"    :  ({"dark", "cold", "damp", "wet"}),
      "tunnel"    :  "dark",
    ]) );

    SetSmell( ([
      "default"  :  "No smell lingers.",
    ]) );
    SetListen( ([
      "default"  :  "The rushing air dampens noise.",
    ]) );
    SetInventory(([
         NPCS + "/yminer" : 2 
    ]));
    SetExits( ([
      "north"  :  ROOMS + "/mine4.c",
      "west"  :  ROOMS + "/mine2.c",
    ]) );
}
