#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;
int eventDecay();

static void create() {
    meal::create();
    SetKeyName("divine mana");
    SetId( ({ "mana","divine mana","divine" }) );
    SetAdjectives( ({ "divine" }) );
    SetShort("a gooey white globe of holy mana");
    SetLong("This substance does not even apper to be edible "
            "but is in fact a source of great nutrition.");
    SetMass(11);
    SetMealType(MEAL_FOOD);
    SetStrength(50);
    SetMealMessages("The mana fills your stomach.",
                    "$N delicatly picks at their glob of mana.");
  call_out( (: eventDecay :), 60);
}

int eventDecay() {
    if (!environment()) { eventDestruct(); return 0; }
   message("food_action",
      "A meal of divine mana dissappears.",
       environment() );
    eventDestruct();
    return 1;
  }
