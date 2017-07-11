// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in a comfortable home");
  SetLong(
    "This comfortable home is owned by a rather wealthy individual. The floor "
    "is entirely covered in decorative rugs, the styles of which suggest that "
    "the owner likely conducts a lot of business in some of the more remote "
    "areas of the world. There is a luxurious bed against the eastern wall."
  );
  SetItems( ([
  ({ "home" }) : (: GetLong :),
  ({ "floor" }) : 
    "There are many decorative rugs lining the floor of the house.",
  ({ "rug", "rugs", "styles" }) : 
    "The rugs lining the floor were likely imported from other parts of "
    "the world.",  
  ({ "bed", "wall" }) : 
    "There is a luxurious bed against the eastern wall.",
  ]) );
  SetItemAdjectives( ([
    "home" : ({ "comfortable" }),
    "rugs" : ({ "decorative" }),
    "bed" : ({ "luxurious" }),
    "wall" : ({ "eastern" }),
  ]) );
  SetInventory( ([
    DAL_NPC "sionn" : 1, 
  ]) );
  SetListen( ([
    "default" : "The sounds of city life drift in from outside.",
  ]) );
  SetSmell( ([
    "default" : "The house smells slightly fragrant, as if some incense was "
      "burned recently.",
  ]) );
  SetExits( ([
    "out" : DAL_ROOM "road8",
  ]) );  
}
