#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("galact");
   SetShort("a mug of galact");
   SetId( ({ "mug","galact" }) );
   SetAdjectives( ({ "mug of" }) );
   SetLong("The galact is contained inside a plain brown mug.  Galact is green-purple "
           "color swirled together, with most of the green hanging towards the bottum "
           "and most of the purple hanging towards the top.");
   SetMealType(MEAL_ALCOHOL);
   SetStrength(55);
   SetMass(7);
   SetMealMessages("The galact glides over your tongue and down into your stomache with "
                   "a smooth, gentle feel.  Sweet cinnamon fruit tastes seem to be "
                   "hidden inside it.  Once it is all consumed, the mug magically "
                   "disintegrates.",
                   "$N drinks some galact.");
   SetProperty("magic","The mug is magically enchanted to disintegrate once it is "
                       "emptied.");
   SetProperty("history","Galact is only made in the deep underground caverns near "
               "Ditmar.  The products of a fungus and a strange fruit-like plant "
               "are combined and fermented to create this strong alcoholic drink.");
}