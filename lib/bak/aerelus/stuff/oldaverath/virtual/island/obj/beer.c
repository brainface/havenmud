// Amelia
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("beer");
   SetShort("a mug of beer");
   SetId( ({ "beer","mug" }) );
   SetAdjectives( ({ "mug of" }) );
   SetLong("A dark brown liquid swirls in the heavy glass mug, topped with "
           "layer of off-white foam. ");
   SetMass(3);
   SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
   SetStrength(15);
   SetMealMessages("You chug the entire mug of beer.",
                   "$N chugs an entire mug of beer.");
   SetEmptyName("mug");
   SetEmptyShort("an empty mug");
   SetEmptyLong("The empty mug contains a dark brown residue.");
}
