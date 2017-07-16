#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("table");
  SetShort("a broken foosball table");
  SetId(({ "table" }));
  SetAdjectives( ({ "broken","foosball" }) );
  SetLong(
    "This foosball table looks a bit long in the tooth. Half the painted men "
    "are broken off, and the turn rods are rusted shut. Someone has stuffed "
    "a styrofoam cup in one of the goal posts, and the ball is nowhere to be "
    "found."
  );
  SetPreventGet("Fuck that, that table's heavy.");
}

