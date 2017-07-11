/* Wandering Bats */

#include <lib.h>
#include "../caves.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("bat");
  SetId( ({"bat"}) );
  SetAdjectives( ({"brown", "small"}) );
  SetShort("a brown bat");

  SetLong("The small, brown bat has a short, but luxerious coat.  Although "
          "small the bat looks as if it could put up some resistance.");

  SetRace("bat");
  SetClass("animal");
  SetLevel(1);
  SetGender("male");
  SetMorality(0);
  SetDie("The bat's wings are clipped as it dies and crashes to the ground.");

  SetAction(4, ({"The bat gives off a high pitched squeak!!!",
                 "There is a leathery flapping of wings.",}) );

  SetWander(2);
  SetProperty("Telgos", 1);
}
