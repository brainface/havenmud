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
    "This is a steak made from horsemeat.  It is very common "
    "in the Goblin Horde."
   );
  SetMealMessages( ({
    "You eat some horse flesh.",
    "$N eats some horse flesh.",
  }) );
}
