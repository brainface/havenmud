
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("dwarven blood");
   SetShort("a flask of dwarven blood");
   SetId( ({ "flask","blood" }) );
   SetAdjectives( ({ "flask of","dwarven" }) );
   SetLong("Red delicious dwarven blood has been placed in this"
           " flask. Due to the notoriety of the dwarven love"
           " for ale, their blood comes packed with alcohol."
           " Someone equipped with a stomach to handle"
           " the consumption of blood will be rewarded with"
           " the effects of alcohol on their body from"
           " drinking this flask.");
   SetMass(5);
   SetStrength(80);
   SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
   SetMealMessages("You pour the contents of the flask down your"
                   " throat, spilling some on your face.",
                   "$N drinks a flask of dwarven blood.");
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
