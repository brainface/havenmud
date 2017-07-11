// Coded by Tassadar 11-26-99
// Fixed by Zeratul 11-28-99
#include <lib.h>
#include "../lake.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("deer");
  SetId( ({"small deer","deer"}) );
  SetShort("a small deer");
  SetLong("The small deer is a mere faun.  It appears to be hungry.");
  SetGender("female");
  SetLimit(3);
  SetRace("deer");
  SetClass("animal");
  SetLevel(3);
  SetWander( 5 + random(2), ({ "go west","go north","go east","go south",
     "go northwest","go northeast","go southwest","go southeast",}), 1 );
  SetDie("The small deer freezes as it dies.");
}
