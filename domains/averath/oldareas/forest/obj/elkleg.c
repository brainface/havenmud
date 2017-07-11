// Amelia
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("leg");
   SetShort("a leg of elk");
   SetId( ({ "leg","leg of elk" }) );
   SetAdjectives( ({ "elk" }) );
   SetLong("A few teeth marks are indented in the leg of elk, but "
           "otherwise, it appears to be perfectly edible.");
   SetMass(20);
   SetMealType(MEAL_FOOD);
   SetStrength(60);
   SetMealMessages("You scarf the leg of elk.",
                   "$N eats a leg of elk.");
   SetEmptyName("bone");
   SetEmptyShort("a bone");
   SetEmptyLong("The only remains of an elk, this leg bone "
                "is polished clean.");
}
