#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("beer");
  SetId( ({"beer","mug","stout mug of beer","mug of beer","stout mug"}) );
  SetShort("a stout mug of beer");
  SetMass(1);
  SetValue(4);
  SetLong("It is a beer in the heavy, stout mug distinctive to the Weary Traveler Inn.");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(14);
  SetMealMessages("You drink the stout mug of beer.","$N drinks a stout mug of beer.");
  SetEmptyName("mug");
  SetId( ({"mug","empty mug"}) );
  SetEmptyShort("an empty mug");
  SetEmptyLong("This is a stout, heavy mug from the Weary Traveler Inn.");
}
