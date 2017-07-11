/*a clearing
  kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
#define CONNECT_ROOM "/domains/valley/virtual/valley/-10,0"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small clearing");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
        "north" : CONNECT_ROOM,
        "east" : MANSION_ROOMS + "clearing5",
        "west" : MANSION_ROOMS + "clearing3",
        "south" : MANSION_ROOMS + "moat3",
        "southwest" : MANSION_ROOMS + "pasture3",
        "southeast" : MANSION_ROOMS + "moat4",
          ]) );
  SetInventory( ([
        CLEARING_NPC + "groundhog" : 2,
             ]) );
  SetSmell( ([
       "default" : "The area smells of long grass.",
           ]) );
  SetListen( ([
        "default" : "Barking dogs can be heard to the east.",
            ]) );
  SetLong("The ground here is covered with small holes that are hidden "
          "quite well by the long grass. A small trail cuts through the "
          "grass and leads to the east. The clearing extends to the east and "
          "west while there appears to be some source of water to the "
         "south.");
  SetItems( ([
        "ground" : "The cround is covered in small holes.",
        "clearing" : (:GetLong:),
   ({"hole", "holes"}) : "These small holes appear to belong to some "
                         "small rodents.",
         "grass" : "The long grass is bleached by the sun.",
      ({"trail", "path"}) : "This path leads to the east.",
        "water" : "The water seems to be to the south.",
           ]) );
  }
