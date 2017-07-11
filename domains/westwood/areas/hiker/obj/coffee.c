#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("steaming coffee");
   SetShort("a cup of steaming coffee");
   SetId( ({ "cup","coffee" }) );
   SetAdjectives( ({ "cup of","steaming","hot","warm","black","potent" }) );
   SetLong("A gentle curl of water vapor rises from the steaming hot "
           "coffee, which is black and looks potent.");
   SetMass(5);
   SetStrength(60);
    SetMealType(MEAL_DRINK|MEAL_CAFFEINE);
   SetMealMessages("The hot coffee almost sears your throat on the way "
                   "down.","$N drinks some hot coffee.");
   SetEmptyName("empty cup");
   SetEmptyShort("an empty cup.");
   SetEmptyLong("Dried up splotches that were once coffee are at the "
                "bottom of the cup.");
   SetSmell("The coffee smells wake you up.");
}
mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
