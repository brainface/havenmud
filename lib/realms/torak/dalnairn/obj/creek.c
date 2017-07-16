//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetShort("a shallow creek");
  SetLong(
    "A shallow creek flows here with fresh crystal clear water."
  );
  SetMealType(MEAL_DRINK);
  SetPortions(-1);
  SetStrength(45);
  SetMealMessages( ({
    "$N drink from the creek",
    "$N drinks from the creek",
  }) );
  SetId( ({
    "creek", "water"
  }) );
  SetKeyName("creek");
  SetAdjectives( ({ 
    "shallow", "clear", "flowing", "fresh"
  }) );
  SetMaterials( ({"natural"}) );
  SetPreventGet("You can't pick up the creek!");
}
