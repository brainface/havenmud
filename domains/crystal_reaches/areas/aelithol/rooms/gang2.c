#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("around some gangue piles");
    SetDomain("Crystal Reaches");
    SetLong(
      "A few piles of gangue still can be seen around the area, but "
      "they are the extremely old ones. Grass and dirt is working "
      "its way among them and slowly making them slowly dissappear "
      "into oblivion. The grass has been trampled and the area has "
      "been disturbed. The trail leads to a destination behind some "
      "of the taller hills."
    );
    SetItems( ([
      ({"stones", "piles", "pile"})  :  (: GetLong :),
      ({"grass", "grasses"})  :
       "The grass has been trampled by activities.",
      ({"stone", "gangue"})  :
      "Old gangue piles are slowly dissappearing into the hills.",
      "dirt"  :
      "Dirt is slowly working its way among the stones.",
      ({"hill", "hills"})  :
      "The hills are steep and rocky.",
      ({"top", "tops"})  :
      "The tops of the hills and rounded.",
      "trail"  :
      "The trail from the south curves away between some large hills.",
    ]) );
    SetItemAdjectives( ([
      "stones"    :  ({"gray", "dark", "dusty", "old"}),
      "gangue"  :  ({"gray", "dark", "dusty", "old"}),
      "hill"  :  ({"steep", "rocky"}),
      "dirt"  :  "dirty",
      "top"    :  "rounded", 
      "trail"    :  ({"well trodden", "used", "frequented"}),
    ]) );
    SetSmell( ([
      "default"  :  "There is little smell.",
    ]) );
    SetListen( ([
      "default"  :  "Grass whispers at it waves in the breeze.",
    ]) );
    SetExits( ([
      "southeast"  :  ROOMS + "/gang.c",
      "northwest"   :   ROOMS + "/minetown.c",
    ]) );
}
