#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("grocery list");
  SetShort("a grocery list");
  SetId(({ "list" }));
  SetAdjectives( ({ "grocery" }) );
  SetLong(
    "A HOA teddy bear letter is stuck to a fridge here by magnet. A list of "
    "necessities is scrawled along the back in a rather urgent font."
  );
  SetPreventGet("Goddamn that is a strong fucking magnet.");
  SetRead("default",
    "Beer!\n"
    "More Beer?\n"
    "Vodka?\n"
    "Aspirin (lots)\n"
    "Ibuprofin (more)\n"
    "Catfood\n"
  );
}

