#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("fountain");
  SetPreventGet("The fountain is much too large to move.");
  SetMealType(MEAL_DRINK);
  SetMealMessages("You drink from the fountain.",
                  "$N drinks from the fountain.");
  SetStrength(100);
  SetId( ({ "fountain" }) );
  SetShort("a large gothic fountain");
  SetAdjectives( ({ "large", "gothic" }) );
  SetPortions(-1);
  SetLong("This fountain is a lovely addition to the center"
          " of the town. It's design compliments the gothic"
          " architecture of the Church of Aetarin perfectly."
          " A small gargoyle in the center of the fountain"
          " spews water from it's mouth which falls into the"
          " basin of the fountain.");
}
