// A swan, proposed by Mahkefel
// Urien@Haven 13JUN2023

#include <lib.h>
#include <std.h>
#include "../world.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("swan");
  SetId( ({ "swan", "bird"}) );
  SetAdjectives( ({ "wild" }) );
  SetRace("bird","swan");
  SetClass("animal");
  SetGender("female");
  SetLevel(random(7) + 2);
  SetShort("a wild swan");
  SetLong("Sleek white feathers encompass the long necked wild swan from "
          "tail feathers to head. A burnt umber coloured beak shows "
          "some grooves and slight dullness from age or use. Overall, "
          "the bird looks well nourished and the size of a ripe pumpkin "
          "at its prime.");
  SetAction(2, ({
     "Swan stretches both wings and places them back in a resting position.",
     "The wild swan waddles about.",
     }) );
}
