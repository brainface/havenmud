
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create(){
  meal::create();
  SetKeyName("gruel");
  SetId( ({
   "gruel","putrid gruel","mug of gruel","mug","mug of putrid gruel"
   }) );
  SetShort("putrid gruel");
  SetMass(1);
  SetValue(1);
  SetLong(
   "This is a mug filled with gruel which very watery and dark brown in color."
   );
  SetMealType(MEAL_FOOD);
  SetStrength(10);
  SetMealMessages(
   "You drink the putrid gruel out of the mug.",
   "$N drinks from a pewter mug."
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
