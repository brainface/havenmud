// A stray pheasant
// Urien@Haven 11JUN2023

#include <lib.h>
#include <std.h>
#include "../world.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("pheasant");
  SetId( ({ "pheasant", "bird"}) );
  SetAdjectives( ({ "stray" }) );
  SetRace("bird","pheasant");
  SetClass("animal");
  SetGender("female");
  SetLevel(random(3) + 2);
  SetShort("a stray pheasant");
  SetLong("This bird has a blue head with red eye "
          "pits. Her white neck feathers form to "
          "emulate a collar bordering off the "
          "rest of her black spotted feathered brown "
          "body. Her talons are somewhat blunted from "
          "traversing on the hard Kailie soil for food. "
          "Her long tail feathers seem ragged and "
          "harmed from a previous encounter preventing "
          "or inhibiting prolonged and steady flight.");
  SetAction(2, ({
     "The pheasant looks about her surroundings.",
     "The stray pheasant pecks on the ground.",
     }) );
}
