#include <lib.h>
#include <meal_types.h>
#include "../rook.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("waterfall");
  SetShort("a waterfall");
  SetMealType(MEAL_DRINK);
  SetAdjectives( ({"cascading","large"}) );
  SetInvis(1);
  SetLong("A large waterfall cascades down from the ceiling of "
    "the room to the floor.  The water is clear and pure.");
  SetPreventGet("You cannot take a waterfall.");
  SetEmptyItem(R_OBJ + "waterfall");
  SetStrength(50);
  SetMealMessages( ({ "$N drink from a waterfall.", 
    "$N drinks from a waterfall.", 
  }) );
 }
