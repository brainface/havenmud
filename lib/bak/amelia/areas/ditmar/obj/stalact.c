#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("stalact");
   SetShort("a cup of stalact");
   SetId( ({ "cup","stalact" }) );
   SetAdjectives( ({ "cup of" }) );
   SetLong("The stalact is held in a large earthen cup.  It is a murky purple "
           "liquid that shines sometimes when held up to the light right.");
   SetMealType(MEAL_DRINK);
   SetStrength(85);
   SetMass(10);
   SetMealMessages("The stalact has a sweet fruity taste.  As it goes down, you can "
                   "feel a tingling sensation of being well-hydrated going to all "
                   "ends of your body.  After all the stalact is drunk up, the cup "
                   "magically disintegrates.",
                   "$N drinks some stalact.");
   SetProperty("magic","It has a magic component that disintegrates the cup after "
               "it is finished.");
   SetProperty("history","Stalact is a mar drink that comes from a strange plant "
               "which grows on stalactites.  The mar use a combination of it and "
               "and stalag, a nutritious fungus that grows on stalagmites, to "
               "make galact, an alcoholic drink.");
}