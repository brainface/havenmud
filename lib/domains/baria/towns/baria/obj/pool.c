//
// Summary: Pool for baria
// Created by: Rhakz@Haven -- Angel Cazares
// Date: 29/05/98
// For: Baria
//
#include <lib.h>
#include <meal_types.h>
#include "../jungle.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pool");
  SetShort("a round pool");
  SetMealType(MEAL_DRINK);
  SetLong("This is a small round pool sitting around the dragon's\n"
          "statue. The citizens of Baria often fill their pottery\n"
          "with its clear water.");
  SetPreventGet("You cannot take the pool!");
  SetPortions(-1);
  SetStrength(20);
  SetMealMessages( ({ "$N drink from a small pool.", 
                      "$N drinks from a small pool.", 
                 }) );
 }

