
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("ale");
  SetId( ({"ale","mug"}) );
  SetShort("dark ale");
  SetMass(1);
  SetValue(5);
  SetLong(
   "It is a dark thick ale with a strong putrid stench."
   );
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(50);
  SetMealMessages(
   "You drink from the mug as ale slowly pours in your mouth.",
   "$N drinks a mug of rot gut."
   );
  SetEmptyName("pewter mug");
  SetId( ({
   "mug","empty mug","empty pewter mug","pewter mug"
   }) );
  SetEmptyShort("an empty pewter mug");
  SetEmptyLong(
   "This is a pewter mug with a dark stains in the bottom of the mug."
   );
}