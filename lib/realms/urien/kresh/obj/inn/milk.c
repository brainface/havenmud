// Urien 110113
// Goblin Alcoholic Milk -- Updated SetLong
// cook.c sells as default inventory 
#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("mare's milk");
  SetShort("a skin of fermented mare's milk");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(20);
  SetPortions(10);
  SetId( ({ "skin", "milk" }) );
  SetAdjectives( ({ "fermented", "mare's", "mare" }) );
  SetLong(
    "This skin contains fermented mare's milk, a staple "
    "of the diet for the Goblin Horde. The milk inside "
    "the skin is pungent and looks to have been fermenting "
    "since its draw. The skin itself is moderate size and "
    "looks to have been made from flexible mare hide."
    );
  SetMealMessages( ({
    "You drink from a skin of fermented mare's milk.",
    "$N drinks from a skin of fermented mare's milk.",
  }) );
}