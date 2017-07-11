#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(40);
    SetShort("end of a mine");
    SetLong(
      "The mine comes to an end here. Recent work of "
      "the miners can easily be seen. Stone is piled up, "
      "waiting to be moved from the area. Water has pooled "
      "on the rock floor and mixed with earth from the walls.  "
      "The resulting soft mud has caked over the floor. A "
      "round hole in the floor is in the far corner. Cool air rushes "
      "out of it from the depths of the earth."
    );
    SetItems( ([
      "mine"  :   (: GetLong :),
      ({"timbers", "timber"}) :
      "Timbers have been put in place to hold the earth up.",
      ({"torches", "torch", "light"})  :
      "Torches have been lit to illuminate the mine.  They flicker "
      "as air from the interior of the mine rushes by.",
      ({"walls", "wall"})  :
      "The dark stone of the mine's walls drips with moisture.",
      ({"stone", "stones"})  :
      "Stones that have been worked out of the hillside are piled "
      "and await transport to the surface.",
      "tunnel"  :
      "The tunnel leads to the south.",
      ({"pebbles", "dust", "mud", "floor", "surface"})  :
      "Pebbles and dust have mixed with the damp surface of "
      "the floor to form mud.",
      ({"mark", "marks", "work"})  :
      "Miners have recently worked here.",
      "earth"  :
      "Some parts of the walls contain earth.  Some of it has "
      "fallen into the floor to contribute to the mud.",
      ({"water", "pools"})  :
      "Water from the damp walls has pooled on the floor.",
      "hole"  :
      "A perfectly round hole has been uncovered in the far "
      "corner by a miner.  Air from the depths of the earth "
      "rushes from it at an incredible rate.",
    ]) );
    SetItemAdjectives( ([
      "torches"    :  "lit",
      "walls"    :  ({"dark", "cold", "damp", "wet"}),
      "tunnel"    :  "dark",
      "mine"  :  ({"damp", "windy"}),  
      "timber"  :  "support", 
      "wall"  :  ({"damp", "moist", "dark", "stone"}),  
      "stone"  :  ({"gangue", "mined"}), 
      "surface"  :  ({"floor", "rock"}),  
      "mark"  :  "miner",  
      "hole"  :  ({"windy", "small", "deep", "round"}),  
    ]) );
    SetSmell( ([
      "default"  :  "No smell lingers.",
    ]) );
    SetListen( ([
      "default"  :  "The rushing air dampens noise.",
    ]) );
    SetInventory(([
       NPCS + "/miner.c" : 6 
    ]));
    SetExits( ([
      "south"  :  ROOMS + "/mine3.c",
    ]) );
}
