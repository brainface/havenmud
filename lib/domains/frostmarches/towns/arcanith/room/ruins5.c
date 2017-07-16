/*  The eastern path  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("road along eastern wall");
  SetClimate("temperate");

  SetNightLight(20);
  SetExits( ([
    "east"   : ROOM "/ruins5a",
    "west"   : ROOM "/ruins2",
  ]) );

  SetDayLong("The road continues to follow along the eastern wall.  Large "
             "weeds push up between the stones of the road.  A large "
             "building dominates the area to the north.  A silver glow "
             "radiates from the wall.");

  SetNightLong("The pale radiance illuminates the road.  A large building "
               "sits to the north.  Weeds spring from the base of the "
               "building.");

  SetItems( ([
    ({ "long tough weeds", "long tough weed", "long weeds", "long weed",
       "tough weeds", "tough weed", "weeds", "weed" })  :
       "Long tough weeds stick out through the cracks of the road.",
    ({ "cracks of the road", "cracks", "crack", "spaces", "space" })  :
       "There are spaces in the road that allow weeds to grow in the road.",
    ({ "eastern road", "road", "street" })  :
       "The street follows along the eastern wall of the city.  The wall's "
       "light illuminates the road.",
    ({ "eastern wall of the city", "eastern wall", "wall of the city",
       "wall" })   :
       "The eastern wall is made of the same white marble that the rest of "
       "wall is made of.  The light glows with a pale radiance.",
    ({ "silver glow", "pale radiance", "silver light", "glow", "radiance",
       "light" })  :
       "The wall of the city glows with a silver light.  The light is "
       "brightest around runes scrawled on the wall.",
    ({ "silver runes", "spidery runes", "silver rune", "spidery rune",
       "runes", "rune" })   :
       "Silver runes cover much of the wall.  The pale radiance seems to be "
       "brightest on the runes.",
    ({ "white marble with flecks of gold", "white marble with flecks",
       "white marble with gold", "white marble", "marble" })   :
       "The wall is made of white marble with flecks of gold.  The marble "
       "is fairly smooth except for the runes carved on its surface.",
    ({ "flecks of gold", "fleck of gold", "gold", "flecks", "fleck" })   :
       "Flecks of gold are embedded in the white marble.",
    ({ "two-story building", "large building", "building" })  :
       "A two-story building looms above the eastern road.  The large "
       "building is still in good shape and could provide shelter.",
  ]) );

  SetSmell( ([
    "default"  : "Dust and decay fills the air.",
  ]) );

  SetEnters( ([
    "building" : ROOM "/store_relic",
  ]) );

  SetListen( ([
    "default"  : "The road is quiet.",
  ]) );

}

