#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("inside the Sheik's Palace");
  SetLong(
    "Large shuttered windows cover the tiled walls in this room, letting in "
    "a bit of breeze from the outside. The intricate tiling from the "
    "courtyard carries on through the various palace rooms, the designs "
    "varying to give a unique feel to each space. Large sitting pillows "
    "litter the floor in groups. An open archway leads back out to the "
    "courtyard."
    );
  SetSmell("The faint scent of palm dates carries in from the courtyard.");
  SetListen("The rustling of palm leaves fills the air.");
  SetItems( ([
    ({ "room", "space" }) : (:GetLong:),
    ({ "tile", "tiling", "design", "designs" }) : 
       "Intricate tilework covers the wall and floors, colored in brilliant "
       "indigo, golds and reds.",
    ({ "wall", "walls" }) : 
       "The walls are tiled and have been cleaned and polished to a high "
       "shine.",
    ({ "floor", "ground" }) :
       "The floors are tiled and have been cleaned and polished to a high "
       "shine. The floor is covered in large silk sitting pillows.",
    ({ "arch", "archway", "courtyard" }) :
       "A large open archway leads back out to the courtyard.",
    ({ "window", "windows", "shutter", "shutters" }) :
       "Large shuttered windows line the walls, affording beautiful views "
       "of the city and letting in ample amounts of airflow.",
    ({ "pillow", "pillows" }) :
       "These silk pillows are large and luxurious offering comfortable "
       "seating. They range a myriad of rich colors that blend nicely with "
       "the tile."
    ]) );
  SetItemAdjectives( ([
    "tile" : ({ "intricate", "colored", "indigo", "golds", "reds", }),
    "wall" : ({ "clean", "cleaned", "polished", "tiled" }),
    "floor" : ({ "clean", "cleaned", "polished", "tiled" }),
    "arch" : ({ "large", "open" }),
    "window" : ({ "large", "shuttered" }),
    "pillow" : ({ "silk", "sitting", "large", "luxurious", "comfortable" }),
    ]) );
  SetInventory( ([
    ]) );
  SetExits( ([
    "north" : YOZRATH_ROOM "palace",
    ]) );
    
}
