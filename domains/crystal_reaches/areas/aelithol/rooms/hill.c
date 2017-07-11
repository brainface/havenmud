#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("through some hills");
    SetDomain("Crystal Reaches");
    SetLong(
      "The hills are very steep, but round at the top where "
      "they command a view of nearly all of the nearby "
      "countryside. The tall brown grass common to the area "
      "is abundant and it waves with the slightest "
      "encouragement from the wind. Rocks of various sizes "
      "litter the area."
    );
    SetItems( ([
      ({"hills", "hill"})  :  (: GetLong :),
      ({"grass", "grasses"})  :
      "The brown grass is a wild grass native to the area.",
      ({"rock", "rocks"})  :
      "Jagged rocks imbedded in the hillsides little these hills and "
      "can be found in great abundance.",
      ({"view", "countryside"})  :
      "Farmers have covered the hills to the west with wheat fields.  "
      "A forest is farther to the east.",
      ({"top", "tops"})  :
      "The tops of the hills and rounded.",
    ]) );
    SetItemAdjectives( ([
      "hills"    :  ({"steep", "tall", "rocky"}),
      "rock"    :  ({"scattered", "big", "small"}),
      "top"    :  "rounded", 
    ]) );
    SetSmell( ([
      "default"  :  "There is little smell.",
    ]) );
    SetListen( ([
      "default"  :  "Grass whispers at it waves in the breeze.",
    ]) );
    SetExits( ([
      "northwest"  :  ROOMS + "/mouth.c",
      "east"   :   ROOMS + "/oppos.c",
    ]) );
}
