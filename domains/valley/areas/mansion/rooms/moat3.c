/* a moat
   kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the banks of a moat");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
          "north" : MANSION_ROOMS + "clearing4",
          "south" : MANSION_ROOMS + "moat2",
          "west" : MANSION_ROOMS + "pasture3",
          "east" : MANSION_ROOMS + "moat4",
          "northeast" : MANSION_ROOMS + "clearing5",
          "northwest" : MANSION_ROOMS + "clearing3",
          "southwest" : MANSION_ROOMS + "pasture4",
       ]) );
  SetInventory( ([
              ]) );
  SetSmell( ([
      "default" : "The stench of the moat water is almost unbearable.",
               ]) );
  SetListen( ([
     "default" : "The stomping of large animals can be heard to the west.",
           ]) );
  SetLong("There seems to be a bend in the moat here. To the southeast is "
          "the corner of the mansion wall. The moat continues to the east, "
          "and to the west lies a pasture. The bank here is more secure then "
          "the banks to the south and large footprints lead south.");
  SetItems( ([
        "bend" : "The moat curves to the east here.",
        "moat" : "The moat water is very green.",
        "water" : "The green water looks very gross.",
    ({ "mansion", "corner", "wall" }) : "The walls are quite large.",
        "pasture" : "The green pasture lies to the west.",
        "bank" : "The bank here is quite sturdy and is covered in footprints.",
    ({ "footprints", "footprint", "prints"}) : "These human prints lead to the south.",
           ]) );
  }
