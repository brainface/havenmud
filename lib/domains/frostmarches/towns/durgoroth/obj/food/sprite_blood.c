#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("sprite blood");
   SetShort("a flask of sprite blood");
   SetId( ({ "flask","blood" }) );
   SetAdjectives( ({ "flask of","sprite" }) );
   SetLong("Red delicious sprite blood has been placed in this"
           " flask. Someone equipped with a stomach to handle"
           " the consumption of blood will experience a slight"
           " energy boost upon drinking the blood of the"
           " quick and nimble sprite race.");
   SetMass(5);
   SetStrength(60);
   SetMealType(MEAL_DRINK|MEAL_CAFFEINE);
   SetMealMessages("You pour the contents of the flask down your"
                   " throat, spilling some on your face.",
                   "$N drinks a flask of sprite blood.");
}

int eventDrink(object who) {
   
  if((who->GetRace() != "daemon")    &&
     (who->GetRace() != "nosferatu") &&
     (who->GetRace() != "orc")       &&
     (who->GetRace() != "gnoll")     &&
     (who->GetRace() != "dragon")    &&
     (who->GetRace() != "ogre")      &&
     (who->GetRace() != "goblin") ) {
   message("system", "Surely a respectable " + who->GetRace() + " wouldn't"
                     " want to drink such a horrible thing.", 
                      environment()); 
   return 0;
  }
  return (meal::eventDrink(who));
  
}
