#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
   SetClimate("temperate");
   SetShort("a sunken area");
    SetDomain("Crystal Reaches");
   SetLong(
     "This area is a great deal more depressed than the "
     "adjoined areas. No trees grow, but a thick moss covers the "
     "porous soil of the depression. The air here seems heavier "
     "than elsewhere, making it very hard to breathe. The ground "
     "climbs to the southwest."
   );
    SetItems( ([
      "moss"  :  
      "It is a dark, thick moss.",
      "depression"  :  (: GetLong :),
      "soil"  :
      "The soil is very thick and black.",
      "undergrowth"  :
     "The undergrowth is very thick northwards, barring all passage.",
    ]) );
    SetItemAdjectives( ([
      "soil"  :   ({"thick", "black"}),
      "undergrowth"  :  ({"thick", "dense"}),
      "moss"  :   ({"thick", "dark"}),
    ]) );
   SetSmell( ([
      "default"  :  "No odor seems to linger.",
    ]) );
    SetListen( ([
      "default"  :  "A bird is singing in the distance.",
    ]) );
    SetInventory(([
       NPCS + "/wood" : 1 
    ]));
    SetExits( ([
      "southwest" : ROOMS + "/thicket.c",
      "east" : ROOMS + "/lake.c",
    ]) );
}
