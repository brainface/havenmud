// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

int timer = 100;

static void create() {
   meal::create();
   SetKeyName("honey milk");
   SetShort("a cup of honey milk");
   SetId( ({ "cup","milk","honey" }) );
   SetAdjectives( ({ "honey","milk","cup","of" }) );
   SetLong("The honey milk is white with a slight tinge towards the "
           "color of honey.  It looks sweet and cool and very "
           "inviting.");
   SetMass(10);
   SetMealType(MEAL_DRINK);
   SetStrength(50);
   SetMealMessages("Yum.  The honey milk is very sweet, but not so "
                   "sweet as to be gross, and it goes down well.",
                   "$N drinks a cup of honey milk.");
   SetTouch("The liquid is smooth and clean and cool.");
   SetSmell("The honey milk smells just like it is named:  It smells "
            "of honey, and it smells of milk.");
   set_heart_beat(2);
   SetProperty("magic","This honey milk was conjured by an Eclat.");
}

void heart_beat() {
   timer--;
   if(!timer) {
      if(environment(this_object())) {
         message("other","The honey milk goes poof.",
                 environment(this_object()));
      }
      eventDestruct();
   }
}
