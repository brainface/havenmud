// Proximo@Pax Imperialis
// 06/20/2003

#include <lib.h>
#include <std.h>
#include "../sulumus.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("gnomish man");
  SetId( ({ "man" }) );
  SetAdjectives( ({ "traveling", "gnomish" }) );
  SetShort("a traveling gnomish man");
  SetLong(
     "This very short, red cheeked fellow is a traveler who wanders the land "
     "learning all that he can to the day he will return to his people with all of "
     "his experiences and knowledge. He seems to have a smile upon his face "
     "almost constantly, savoring every moment in his trip away from home. "
  	 );
  SetGender("male");
  SetLimit(1);
  SetRace("gnome");
  SetWander(1+random(4));
  SetClass("rogue");
  SetLevel(12);
  SetInventory( ([
  ]) );
  SetFriends( ({
  }) );
  SetCurrency("imperials", 25 + random(110));
  SetMorality(-1);
  SetAction(2, ({
     "!say Ahh hello there. ",
     "!hum",
     "!laugh",
     "!hmm",
     "!say Don't be looking at me funny now.",
     "!say This place is dull",
     "!say I've been away from home from so long...",
     "!say I've learned a few skills on my journey.",
     "!say Don't mess with me!",
  }) );
  SetCombatAction(5, ({
  }) );
}
