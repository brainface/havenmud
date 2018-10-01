#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("vodka");
  SetId( ({ "fifth", "fifth of vodka", "vodka"}) );
  SetAdjectives( ({ "fifth","of","discount" }) );
  SetShort("a fifth of discount vodka");
  SetMass(30);
  SetValue(10);
  SetLong("This unlabeled glass bottle is full of discount "
    "vodka. Get ready to dance, because the cost savings "
    "were flavour and water, not vodka. Bottoms up!");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(150);
  SetMealMessages("You down the fifth of vodka and do a graceful little happy dance.",
                  "$N downs a fifth of vodka and starts seizing in a vaguely dancelike manner.");
  SetEmptyName("fifth");
  SetEmptyShort("an empty fifth");
  SetEmptyLong("This is an empty fifth of something terribly strong and potato based.");
}

