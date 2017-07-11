
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("stew");
   SetShort("muezzin stew");
   SetId( ({ "stew" }) );
   SetAdjectives( ({ "muezzin" }) );
   SetLong("Large chunks of meat cling to humanoid bones in the piping hot stew.");
   SetMass(5);
   SetStrength(60);
   SetMealType(MEAL_FOOD);
   SetMealMessages("The muezzin stew is quite possibly the most delicious "
		"meal you have ever eaten.  The overcooked meat is tender, "
		"and even without spices, the gravy is scrumptious.",
                   "$N eats some muezzin stew.");
   SetSmell("The stew has a strong meaty aroma.");
}
