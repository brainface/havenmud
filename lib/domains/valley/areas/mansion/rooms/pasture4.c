/* a small pasture
    kyla 1-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small pasture");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
         "north" : MANSION_ROOMS + "pasture3",
         "south" : MANSION_ROOMS + "pasture5",
         "east" : MANSION_ROOMS + "moat2",
         "northeast" : MANSION_ROOMS + "moat3",
         "southeast" : MANSION_ROOMS + "moat1",
         "northwest" : MANSION_ROOMS + "pasture2",
          ]) );
  SetInventory( ([
            PASTURE_NPC + "goat" : 3,
            PASTURE_NPC + "shepherd" : 1,
              ]) );
  SetSmell( ([
       "default" : "There is the distinct smell of large farm animals "
                   "in this area.",
          ]) );
  SetListen( ([
        "default" : "Mooing can be heard to the west and to the north.",
           ]) );
  SetLong("This area of the pasture seems to be heavily travelled. "
          "What grass is left is completely flattened and the ground is "
          "quite muddy. To the east there seems to be a moat and to the "
          "west lies a large door. The grass seems to be healthier to the "
           "north and south.");
  SetItems( ([
         "grass" : "The grass here is flattened and mixed with the mud.",
       "barn" : "The barn is very large.",
        "mud" : "This mud is very dirty.",
         "ground" : "The ground is quite muddy and covered in footprints.",
      ({ "footprints", "footprint" }) : "These are large hooved prints.",
         "moat" : "The moat is barely visible to the east.",
         "door" : "The door has been left the slightest bit open.",
           ]) );
  SetEnters( ([
        "door" : MANSION_ROOMS + "barn2",
        "barn" : MANSION_ROOMS + "barn2",
           ]) );
  }
