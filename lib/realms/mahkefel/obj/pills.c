#include <lib.h>
inherit LIB_ITEM;

void eventDancePunk();

static void create() {
  ::create();
  SetKeyName("ibuprofen");
  SetShort("a generic bottle of ibuprofen");
  SetId( ({ "bottle", "ibuprofen" }) );
  SetAdjectives( ({ "generic", "bottle", "of" }) );
  SetLong("A huge white plastic pill bottle, with a largely defective "
    "child safety cap that is easily removed. A comforting rattle of "
    "many, many pills sounds when the bottle is rattled.");
  SetMass(100);
  SetValue(10);
}


