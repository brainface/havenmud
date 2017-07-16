#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("ale");
  SetId( ({ "ale", "mug" }) );
  SetShort("a mug of mild ale");
  SetMass(10);
  SetValue(3);
  SetLong("This is a mug of mild ale.");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(15);
  SetMealMessages("You drink the mug of ale.","$N drinks a mug of ale.");
  SetEmptyName("mug");
  SetId( ({"mug","empty mug"}) );
  SetEmptyShort("an empty mug");
  SetEmptyLong("This is a small mug from the Morning Star Inn.");
}
