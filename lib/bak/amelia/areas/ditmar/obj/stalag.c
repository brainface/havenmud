#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("stalag");
   SetShort("a bowl of stalag");
   SetId( ({ "bowl","stalag" }) );
   SetAdjectives( ({ "bowl of" }) );
   SetLong("Stalag is a dark green fungus with the occasional blue streak running "
           "through it.  It is an extremely nutritious type of food.");
   SetMealType(MEAL_FOOD);
   SetStrength(85);
   SetMass(5);
   SetMealMessages("The stalag has a faintly cinnamonny taste.  It goes down easily.  "
                   "When the stalag is all emptied out of the bowl, the bowl magically "
                   "disintegrates.",
                   "$N eats some stalag.");
   SetProperty("magic","The bowl is charmed to magically disintegrate when all the "
               "stalag is emptied from it.");
   SetProperty("history","Stalag is a traditional food for the mar.  It is a fungus "
               "that grows on stalagmites that the citizens of Ditmar have learned "
               "to harvest.  It is very nutritious.");
}