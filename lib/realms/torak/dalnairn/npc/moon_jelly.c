//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("jellyfish");
  SetId( ({"jellyfish"}) );
  SetAdjectives( ({"moon"}) );
  SetShort("a moon jellyfish");
  SetLong(
  "This is a small translucent jellyfish. "
  "Four horseshoe shaped gonads are visible through the top of its bell. "
  );
  SetRace("slug");
  SetClass("animal");
  SetLevel(1);
  SetLimit(5);
}
