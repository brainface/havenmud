// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("meza");
   SetShort("a steaming cup of meza");
   SetId( ({ "steaming cup of meza","steaming cup","cup of meza","cup",
             "meza","steaming meza" }) );
   SetAdjectives( ({ "steaming" }) );
   SetLong("The meza is a hot brownish liquid that fills the cup nearly "
           "to the brim, but only the steam spills over the edge.");
   SetMass(5);
   SetMealType(MEAL_CAFFEINE|MEAL_DRINK);
   SetStrength(27+random(4));
   SetMealMessages("The cinnamon-tasting meza suddenly awakens you!",
                   "$N drinks some meza.");
   SetEmptyName("cup");
   SetEmptyShort("an empty cup.");
   SetEmptyLong("Small drops of a brownish liquid remain at the bottom "
                "of this chilly cup.");
   SetSmell("The meza smells of cinnamon and richness.");
}
mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
