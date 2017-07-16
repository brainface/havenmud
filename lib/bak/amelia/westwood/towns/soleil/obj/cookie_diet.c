#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   SetKeyName("diet cookie");
   SetId( ({ "cookie" }) );
   SetAdjectives( ({ "tiny","diet" }) );
   SetShort("a tiny diet cookie");
   SetLong("This cookie is an ugly brown-green color.  It's supposed "
           "to taste good, it even has some writing on it to that "
           "effect.  Bland brown frosting with lumps of who-knows-what "
           "in it makes a ring around the edge of the cookie.");
   SetRead("The writting reads:  Eat me!  I won't make you fat, but "
           "I still taste good!");
   SetMass(1);
   SetMealType(MEAL_POISON|MEAL_FOOD);
   SetStrength(5);
   SetMealMessages("You twist your face into a gross look, "
                      "feeling like you're about to vomit.",
                   "$N looks sick after eating a diet cookie.");
   SetSmell("The cookie smells like musty books that have lived "
            "in the damp corner of a basement for far too long.");
   SetTouch("The cookie is rock solid, it's amazing they aren't "
            "used for building houses instead of bricks.  Small "
            "bumps can be felt where some words have been "
            "molded into the cookie.  A little frosting sticks to "
            "your finger, and pondering the taste, you lick it "
            "off--and are immediately sick to your stomach.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
