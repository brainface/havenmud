#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("dwarven blood");
   SetShort("a flask of goden blood");
   SetId( ({ "flask","blood" }) );
   SetAdjectives( ({ "flask of","goden" }) );
   SetLong("Red delicious goden blood has been placed in this"
           " flask. The goden mentality for the aquatic life"
           " makes their blood good for simple ingestion to"
           " quench your thirst, given your stomach can"
           " handle the consumption of blood.");
   SetMass(5);
   SetStrength(80);
   SetMealType(MEAL_DRINK);
   SetMealMessages("You pour the contents of the flask down your"
                   " throat, spilling some on your face.",
                   "$N drinks a flask of goden blood.");
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
