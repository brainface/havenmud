#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("fenfir sap");
   SetShort("a small droplet of fenfir sap");
   SetId( ({"droplet","sap","fenfir sap"}) );
   SetAdjectives( ({ "small","fenfir" }) );
   SetLong("This is a tiny droplet of sap from a fenfir tree.");
   SetMass(2);
   SetMealType(MEAL_DRINK);
   SetStrength(15);
   SetMealMessages("The sap taste slightly bitter.",
                   "$N guzzles down a drop of fenfir sap.");
   SetSmell("The sap smells slightly bitter.");
   SetTouch("The drop of fenfir sap is slightly sticky to touch.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
