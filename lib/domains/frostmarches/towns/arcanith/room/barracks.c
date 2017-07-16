/* The haunted barracks of Arcanith - by Sardonas*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("an ancient barracks");
  SetClimate("indoors");
  SetAmbientLight(10);
  SetExits( ([
    "out"   : ROOM "/ruins5a",
  ]) );

  SetLong("The ancient barracks is definately well built.  It is very "
          "defensible and sound.  Large bars cover the the windows, while "
          "a large oaken door could have once prevented entry from the "
          "street.  Sparse furniture lay decaying around the room.  "
          "However, a chill fills the room, as if the touch of death has "
          "decided to defend the town.");

  SetItems( ([
    ({ "barracks" })  :
       (: GetLong :),
    ({ "oaken door", "rotten door", "door" })   :
       "Upon closer inpections it is reveiled that the door has rotted, and "
       "the hinges have rusted in an open position.  There is no way to "
       "close the door.  At one time the door could have been barred from "
       "the inside.",
    ({ "rusted hinges", "rusted hinge", "hinges", "hinge" })  :
       "The hinges that allow the door to move have rusted open.",
    ({ "rotting furniture", "rotting furnishings", "rotting furnishing",
       "furniture", "furnishings", "furnishing" })  :
       "The furnishings are very old and simple.  A large table with chairs "
       "fill one area of the barracks.  The remainder of the barracks are "
       "occupied by rotting beds.",
    ({ "large table", "table" })  :
       "The table is long and rotting.  At one time the soldiers may have "
       "gathered around the table to share meals.",
    ({ "wooden chair", "wooden chairs", "chair", "chairs" })  :
       "Wooden chairs surround the table.  At one time they would have "
       "supported weight; now they can barely support themselves.",
    ({ "rotting beds", "rotting bed", "beds", "bed" })  :
       "The beds would have been comfortable at one time; now the only thing "
       "that could be comfortable on them are mushrooms and mold.",
    ({ "mushroom", "mushrooms", "mold" })  :
       "Mushrooms and mold grow on the rotting furniture.",
    ({ "large metal bars", "large metal bar", "large bars", "large bar",
       "bars", "bar" })   :
       "Large metal bars are set in the barrack's windows.  At one time they "
       "would have defended the barracks from invaders; now they are covered "
       "in rust and are decaying.",
    ({ "orange-red rust", "rust" })  :
       "Orange-red rust covers the bars blocking the windows.",
    ({ "large windows", "large window", "window", "windows" })   :
       "Large windows allow air to circulate in the barracks.  Large bars "
       "cover the windows, but are rusting away.",
  ]) );

  SetSmell( ([
    "default"  : "The smell of death hangs in the air.",
  ]) );
  SetInventory( ([
     NPC "/spirit_warrior" : 1 ]) );

}
