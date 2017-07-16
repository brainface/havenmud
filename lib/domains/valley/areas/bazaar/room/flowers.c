/* Here is a simple booth with bouquets of flowers. */
#include <lib.h>
#include "../bazaar.h"
  inherit LIB_ROOM;

static void create (){
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a flower booth");
  SetLong("This is a small canopy-covered booth decorated with "
     "an array of flowers. The colors in the room give it "
     "a cheerful glow. There is a wooden table against "
     "the back of the booth where several vases full "
     "of daisies, peonies, and tulips are sitting. "
     "The ticket booth is back to the south and another "
     "canopy is visible to the west.");
  SetListen( ([
     "default" : "The sounds of laughter drift in from the west."
  ]) );
  SetSmell( ([
     "default" : "The pleasant scent of the flowers fills the room."
  ]) );
  SetItems( ([
   ({ "booth" }) : "A pale canvas canopy is held up by four sticks in the ground.",
   ({ "canopy" }) : "It is made of a pale, striped canvas.",
   ({ "flower", "flowers" }) : "There are all sorts of flowers here. You see daisies, peonies, and tulips in great abundance.",
   ({ "table" }) : "Vases holding daisies, peonies, and tulips are on the table.",
   ({ "vase", "vases" }) : "They are plain clay vases filled with flowers.",
   ({ "daisy", "daisies" }) : "They have white petals and yellow centers.",
   ({ "peony", "peonies" }) : "There are several colors of them, including white, red, and pink.",
   ({ "tulip", "tulips" }) : "Most of them are red.",
  ]) );
   SetItemAdjectives( ([
   "booth" : ({ "small", "canopy-covered" }),
   "table" : ({ "wooden" }),
   "vase" : ({ "several", "plain", "clay" }),
   "canopy" : ({ "canvas" }),
  ]) );
  SetExits( ([
     "south" : BAZAAR_ROOM "booth",
     "west" : BAZAAR_ROOM "empty",
  ]) );
  SetInventory( ([ BAZAAR_NPC + "lilah" : 1, ]) );
}
