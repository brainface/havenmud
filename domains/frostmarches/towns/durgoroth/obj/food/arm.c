
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("arm");
   SetShort("a rotting arm of a daemon");
   SetId( ({ "arm" }) );
   SetAdjectives( ({ "rotting","daemon" }) );
   SetLong("This arm has been severed from the torso"
           " of a daemon. It is slightly rotten and"
           " has an awful odor to it.");
   SetMass(15);
   SetStrength(30);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N devour a daemon arm.",
                   "$N devours an arm of a daemon.");
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

