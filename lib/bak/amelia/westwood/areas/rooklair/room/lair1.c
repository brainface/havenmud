#include <lib.h>
inherit LIB_ROOM;
#include "../rook.h"
 
static void create() {
room::create();
  SetDomain("WestWood");
  SetShort("inside a sinkhole");
  SetDayLong("The sinkhole is large in size and the opening is round.  "
    "The daylight from outside filters down and "
    "lights the area a small amount.  Small amounts of grass and vines "
    "slightly cover the opening, hiding it ever so slightly.  A large "
    "tunnel leads to the southeast and the small rope dangles down "
    "from above.");
  SetNightLong("The sinkhole is large in size and the opening is round.  "
    "There is no natural lighting here.  Small amounts of grass and "
    "vines slightly cover the opening, hiding it ever so slightly.  A "
    "large tunnel leads to the southeast and the small rope dangles "
    "down from above.");
  SetAmbientLight((query_night() ? SetAmbientLight(0) : 
  SetAmbientLight(15) ));
  SetClimate("indoors");
  SetItems( ([
    ({"sinkhole"}) : "The sinkhole is large and probaly caused by the "
      "erosion of many years of rainfall in the WestWood.",
    ({"opening","above"}) : "The opening above is partially hidden "
      "concealed by grass and vines.",
    ({"grass","vines","vine"}) : "The grass and the vines are green and "
      "slightly hide the opening above.",
    ({"tunnel"}) : "The tunnel is very large and leads off to the "
      "southeast.",
    ({"rope"}) : "A small rope dangles in from above.",
    ({"light","daylight"}) : (query_night() ? "There is no light inside "
      "the sinkhole." : "The light filters in through the sinkhole "
      "opening."),
  ]) );
  SetItemAdjectives( ([
    "sinkhole" : ({"large"}),
    "opening" : ({"round"}),
    "light" : ({"day"}),
    "tunnel" : ({"large"}),
  ]) );
  SetExits( ([
    "southeast" : R_ROOM + "lair2",
  ]) );
  SetInventory( ([
    R_OBJ + "rope2" : 1,
  ]) );
  SetSmell( ([
    "default" : "The rooms smells of mold and dust.",
  ]) );
  SetListen( ([
    "default" : "The light sounds of forest life can be heard.",
  ]) );
}
