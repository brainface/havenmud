#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create(); 
   SetKeyName("mug of coffee");
   SetShort("a mug full of warm coffee");
   SetId( ({ "coffee mug","coffee","mug","liquid" }) );
   SetAdjectives( ({ "mug of","mug full of","warm","brown" }) );
   SetLong("A little steam rises from the brown liquid inside the "
           "mug.");
   SetMass(5);
   SetMealType(MEAL_DRINK|MEAL_CAFFEINE);
   SetStrength(15);
   SetMealMessages("Drinking the coffee, you realize that it may have "
                   "been best to just smell the nice aroma:  It "
                   "doesn't taste as good as it smells.",
                   "$N seems a little more hyper after drinking a "
                   "bit of coffee.");
   SetEmptyName("mug");
   SetEmptyShort("a coffee mug");
   SetEmptyLong("A little brown stain has formed in the bottum of the "
                "mug.");
   SetSmell("Deliciously awakening coffee smells come from the mug.");
}
