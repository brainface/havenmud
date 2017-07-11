/* This is the site of a fortune teller. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("a mysterious tent");
  SetLong("This quiet tent seems to almost be in a separate world from "
     "the rest of the bazaar. Candles line the edges of the table in the "
     "middle of the room and are also placed on the dirt floor along the "
     "walls of the tent. A luminous glass ball sitting in the center of the "
     "table is surrounded by strings of star-shaped beads. The only "
     "way out is through the tent flap to the north.");
  SetItems( ([
   ({ "tent" }) : (: GetLong :),
   ({ "candle", "candles" }) :
     "The candles line the edges of the room and the table. They cast flickering "
     "shadows all along the walls of the tent.",
   ({ "bead", "beads" }) : "The strings of pure silver star-shaped beads are arranged in swirly patterns around the glass ball.",
   ({ "ball" }) : "This radiant glass ball gives off a warm light. Looking into the ball, there seem to be "
     "shadows dancing and beckoning.",
   ({ "table" }) : "In the center of the candle-lined table rests a luminous glass ball. Silver beads form patterns around the ball.",
   ({ "flap" }) : "This canvas opening leads back to the rest of the bazaar.",
   ({ "floor" }) : "There are candles on the dirt floor all along the edges of the room.",
   ({ "shadow", "shadows" }) : "The light from the candles forms eerie shadows that seem to dance.",
  ]) );
  SetItemAdjectives( ([
   "tent" : ({ "quiet" }),
   "ball" : ({ "glass", "luminous" }),
   "bead" : ({ "strings of", "star-shaped", "silver" }),
   "flap" : ({ "tent" }),
   "floor" : ({ "dirt" }),
   "shadow" : ({ "flickering" }),
  ]) );
  SetSmell( ([
     "default" : "You smell candles burning.",
  ]) );
  SetListen( ([
     "default" : "It is strangely quiet.",
  ]) );
  SetExits( ([
     "out" : BAZAAR_ROOM "acc"
  ]) );
  SetInventory( ([ BAZAAR_NPC + "raevynn" : 1, ]) );
}
