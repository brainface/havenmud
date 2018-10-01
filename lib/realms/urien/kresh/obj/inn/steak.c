// Urien 110113
// Goblin Horsemeat -- Updated SetLong
// cook.c sells as default inventory 
#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("horsemeat");
  SetShort("a steak of horsemeat");
  SetId( ({ "meat", "horsemeat", "steak" }) );
  SetAdjectives( ({ "steak", "horse", "meat" }) );
  SetMealType(MEAL_FOOD);
  SetPortions(2);
  SetStrength(30);
  SetLong(
    "This is a cut steak made from horsemeat. It is very common "
    "in the Goblin Horde. The steak is charred on one side "
    "and completely raw on the other. It looks a good size, "
    "enough to curve off some hungry craving."
   );
  SetMealMessages( ({
    "You eat some horse flesh.",
    "$N eats some horse flesh.",
  }) );
}
