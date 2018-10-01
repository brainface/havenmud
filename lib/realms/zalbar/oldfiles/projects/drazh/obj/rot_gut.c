
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("rot gut");
  SetId( ({"rot gut","mug"}) );
  SetShort("a mug of rot gut");
  SetMass(1);
  SetValue(2);
  SetLong(
	 "It is a dark ale with a strong musty odor."
	 );
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(25);
  SetMealMessages(
	 "You drink from the mug as the rot gut burns your innards.",
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