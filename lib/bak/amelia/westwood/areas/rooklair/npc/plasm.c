#include <lib.h>
#include "../rook.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("smoke");
  SetRace("wraith","plasm");
  SetId( ({ "wisp of smoke","smoke","wisp" }) );
  SetAdjectives( ({ "wisp" }) );
  SetShort("a wisp of smoke");
  SetLevel(1);
  SetClass("animal");
  SetLong("This is a wisp of smoke.");
  SetMorality(0);
}
