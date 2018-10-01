//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include "../../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("on the second floor");
  SetLong(
    "The second floor of the wooden building is adorned with windows. "
    "and the walls are painted in a whitewash. Thick wooden columns "
    "raise from the floor and support the ceiling above. "
    "Rows of chairs facing a podium have been placed "
    "neatly here.",
  );
  SetItems( ([
    ({ "podium" }) : 
       "A wooden podium has been placed near the back wall.",
    ({ "windows" }) :
       "There are many open windowframes here. Each is framed in wood "
       "and lacking glass panels. ",
    ({ "door" }) :
       "The blue door swings freely on its hinges and has no handle nor knob. "
       "It separates the front of the restaurant from the kitchen.",
    ({ "rows", "chairs" }) :
       "Rows of chairs have been set up here facing a podium "
       "against the back wall.",
    ({ "restaurant", "building", "second floor" }) :
      (: GetLong :),
    ({ "back wall" }) :
       "The back wall is painted white. A podium is placed here between the windows.",
    ({ "column", "columns" }) :
       "Thick wooden columns rise up from the floor and support the ceiling above.",
    ({ "ceiling" }) :
       "The wooden ceiling above is painted white and supported by thick wooden columns.",
    ({ "floor", "planks" }) :
       "The wooden floor is made of planks and painted white.",
    ({ "paint" }) :
       "The restaurant is painted white.",
    ({ "wall", "walls" }) : 
      "The wooden walls of the restaurant are painted white and no "
      "dirt mars their surface.",
  ]) );
  SetItemAdjectives( ([
    "podium" : ({ "wooden" }),
    "rows" : ({ "rows", "of" }),
    "restaurant" : ({ "large", "open", "white", "painted", "wooden", "inside" }),
    "wall" : ({ "white", "clean", "wooden", "wood", "painted" }),
    "column" : ({ "thick", "wooden", "wood" }),
    "ceiling" : ({ "wood", "wooden", "painted", "white", "supported" }),
    "floor" : ({ "wood", "wooden", "painted", "white" }),
    "paint" : ({ "white" }),
  ]) );

  SetInventory( ([ 
    DAL_OBJ "window" : 1,
    DAL_OBJ "rest_stairs_02" : 1,
  ]) );
  SetSmell( ([
    "default" : "Aromas wafting up from the restaurant are mixed with fresh salty air.",
  ]) );
  SetListen( ([    "default" : "Muted echoes of waves and beach life caress the room.",
  ]) );
  SetExits( ([
  ]) );
  SetEnters( ([
  ]) );
}
