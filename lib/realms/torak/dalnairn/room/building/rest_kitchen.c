//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include "../../dalnairn.h"
#include "/domains/valley/areas/bazaar/bazaar.h"
#include "/domains/southern_coast/towns/haven/haven.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("inside a kitchen");
  SetLong(
    "The walls of the kitchen are painted white. "
    "The back walls are lined with tables while front wall is bare except "
    "for a clock hanging next to a blue door. "
    "Thick wooden columns rise up from the floor supporting the ceiling above. "
  );
  SetItems( ([
    ({ "food", "foods", "ingredients", "ingredient" }) :
       "Various ingredients are being prepped for use on the tables.",
    ({ "tables", "stations" }) :
       "The wooden tables lining the walls are used as preperation "
       "stations for the foods of the kitchen.",
    ({ "door" }) :
       "The blue door swings freely on its hinges and has no handle nor knob. "
       "It separates the front of the restaurant from the kitchen.",
    ({ "restaurant" }) :
       "You can not see the restaurant from here.",
    ({ "kitchen" }) :
      (: GetLong :),
    ({ "front wall" }) :
       "The front wall is painted white and decorated with a clock. "
       "A blue door leads out to the front of the restaurant.",
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
      "dirt mars their surface. Tables line the walls.",
  ]) );
  SetItemAdjectives( ([
    "tables" : ({ "preperation", "wood", "wooden" }),
    "rows" : ({ "two", "rows", "of" }),
    "restaurant" : ({ "large", "open", "white", "painted", "wooden", "inside" }),
    "wall" : ({ "white", "clean", "wooden", "wood", "painted", "back" }),
    "column" : ({ "thick", "wooden", "wood" }),
    "ceiling" : ({ "wood", "wooden", "painted", "white", "supported" }),
    "floor" : ({ "wood", "wooden", "painted", "white" }),
    "paint" : ({ "white" }),
  ]) );
  SetInventory( ([ 
    DAL_NPC "controller" : 1,
    H_OBJ "clock" : 1,
    DAL_OBJ "prep_table" : 1,
  ]) );
  SetSmell( ([
    "default" : "Aromas of food and spices permeate the kitchen delightfully.",
  ]) );
  SetListen( ([
    "default" : "The din of muted conversation emenates from the restaurant.",
  ]) );
  SetExits( ([
    "out" : DAL_BLD + "rest_01",
  ]) );
  SetEnters( ([
  ]) );
}
