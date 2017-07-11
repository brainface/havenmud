#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("hooves");
   SetShort("a rotting hooves of a daemon");
   SetId( ({ "hooves" }) );
   SetAdjectives( ({ "rotting","daemon" }) );
   SetLong("This hooves has been severed from the body"
           " of a daemon. It is slightly rotten and"
           " has an awful odor to it.");
   SetMass(10);
   SetStrength(15);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N devour some daemon hooves.",
                   "$N devours the hooves of a daemon.");
}

int eventEat(object who) {

  if((who->GetRace() != "daemon")    &&
     (who->GetRace() != "nosferatu") &&
     (who->GetRace() != "orc")       &&
     (who->GetRace() != "gnoll")     &&
     (who->GetRace() != "dragon")    &&
     (who->GetRace() != "ogre")      &&
     (who->GetRace() != "goblin") ) {
   message("system", "Surely a respectable " + who->GetRace() + " wouldn't"
                     " want to eat such a horrible thing.", 
                      environment()); 
   return 0;
  }
  return (meal::eventEat(who));
}

