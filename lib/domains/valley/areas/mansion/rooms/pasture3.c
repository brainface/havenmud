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
  SetExits( ([
          "north" : MANSION_ROOMS + "clearing3",
          "south" : MANSION_ROOMS + "pasture4",
          "east" : MANSION_ROOMS + "moat3",
          "west" : MANSION_ROOMS + "pasture2",
          "southeast" : MANSION_ROOMS + "moat2",
          "northeast" : MANSION_ROOMS + "clearing4",
          "northwest" : MANSION_ROOMS + "clearing2",
            ]) );
  SetClimate("temperate");
  SetInventory( ([
          PASTURE_NPC + "cow" : 1,
              ]) );
  SetListen( ([
        "default" : "Animal sounds can be heard from all directions.",
           ]) );
  SetSmell( ([
       "default" : "The scent of hay and straw is strong here.",
           ]) );
  SetLong("This part of the pasture seems to be where the animals "
          "do most of their grazing. The grass is short and very "
          "trampled. A large building can be seen to the south and "
          "there appears to be a clearing of some sort to the north. "
          "The pasture continues on to the west and to the east lies "
          "a moat.");
  SetItems( ([
        "grass" : "The grass here is short and has been crushed by "
                  "constant travel.",
        "building" : "This is a large wooden building.",
        "clearing" : "What appears to be a clearing lies to the north.",
         "moat" : "A small moat lies to the east.",
          ]) );
  }


