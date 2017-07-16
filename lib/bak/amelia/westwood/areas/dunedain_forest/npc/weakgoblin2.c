#include <lib.h>
#include "../forest.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("goblin");
  SetShort("a weak looking goblin");
  SetLong("This is a weak looking goblin.  His bones are clearly "
          "visible and he looks around with a hungry look in his eyes. "
          "The goblin moves from place to place foraging for food.");
  SetId( ({ "gobline", "weak looking goblin" }) );
  SetAdjectives( ({ "angry", "weak looking" }) );
  SetClass("fighter");
  SetMorality(-175);
  SetWander(25, ({ "enter cave","out","go southeast","go east",
                       "go west","go northwest" }), 0);
  SetLevel(random(3)+7);
  SetGender("male");
  SetRace("goblin");
  SetCurrency("imperials",random(5));
  SetInventory( ([
                   F_OBJ "knife" : "wield knife",
              ]) );
}
