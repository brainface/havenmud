#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("leaf dew");
   SetShort("a small thimble of leaf dew");
   SetId( ({"thimble","dew","leaf dew"}) );
   SetAdjectives( ({ "small","lead" }) );
   SetLong("This tiny thimble is full of leaf dew.");
   SetMass(2);
   SetMealType(MEAL_DRINK);
   SetStrength(10);
   SetMealMessages("The dew taste clean.",
                   "$N drinks from a thimble.");
   SetSmell("The dew smells clean.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
