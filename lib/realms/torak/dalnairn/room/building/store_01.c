//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include <std.h>
#include "../../dalnairn.h"
#include "/domains/valley/areas/bazaar/bazaar.h"
#include "/domains/southern_coast/towns/haven/haven.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("inside a store");
  SetLong(
    "A store. a counter. things for sale. box of cigars. door out. "
  );
  SetItems( ([
    ({ "door" }) :
       "The blue door swings freely on its hinges and has no handle nor knob. "
       "It separates the front of the restaurant from the kitchen.",
    ({ "kitchen" }) :
       "You can not see the kitchen from here.",
    ({ "rows", "tables", "chairs" }) :
       "Two rows of tables and chairs have been set up for hungry guests. "
       "Each table is adorned with a red and white checkered tablecloth, "
       "a white candle and a pair of tulips.",
    ({ "restaurant", "building" }) :
      (: GetLong :),
    ({ "back wall" }) :
       "The back wall is painted white and decorated with a clock and black flag. "
       "A blue door leads to the back of the restaurant.",
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
    "rows" : ({ "two", "rows", "of" }),
    "restaurant" : ({ "large", "open", "white", "painted", "wooden", "inside" }),
    "wall" : ({ "white", "clean", "wooden", "wood", "painted" }),
    "column" : ({ "thick", "wooden", "wood" }),
    "ceiling" : ({ "wood", "wooden", "painted", "white", "supported" }),
    "floor" : ({ "wood", "wooden", "painted", "white" }),
    "paint" : ({ "white" }),
  ]) );
  SetInventory( ([ 
    DAL_NPC "equipper" : 1,
    DAL_NPC "clerk" : 1,
  ]) );
  SetSmell( ([
    "default" : "The air is crisp and salty.",
  ]) );
  SetListen( ([
    "default" : "Noises of the beach echo mutely inside the wooden building.",
  ]) );
  SetExits( ([
    "out" : DAL_ROOM + "2,0",
  ]) );
  SetEnters( ([
  ]) );
}
