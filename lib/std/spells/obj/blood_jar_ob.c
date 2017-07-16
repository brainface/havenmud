#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("jar");
  SetId( ({ "jar", "jar of blood" }) );
  SetShort("a jar of blood");
  SetProperty("magic", "This red jar was created from a combination of blood and "
  "magic energies.");
  SetMass(20);
  SetDestroyOnSell(1);
  SetLong("This magical jar is filled with blood.");
  SetMealType(MEAL_DRINK);
  SetStrength(20);
  SetValue(0);
  SetMealMessages("Blood drips down your chin as you drink from the jar.",
                  "$N drinks some blood.");
}

mixed eventDrink(object who) {
if ((this_player()->GetRace() == "orc")    ||
      (this_player()->GetRace() == "gnoll")  ||
      (this_player()->GetRace() == "goblin") ||
      (this_player()->GetRace() == "ogre")   ||
      (this_player()->GetRace() == "dragon") ||
      (this_player()->GetRace() == "daemon") ||
      (this_player()->GetRace() == "nosferatu") ||
      (this_player()->GetSkillLevel("necromancy") > 0 )) {
    who->AddHealthPoints(120);
    who->eventDisplayStatus();
  return meal::eventDrink(who); 
  }
  else {
    who->eventPrint((capitalize(pluralize(who->GetRace())) + 
               " do not like the taste of blood!"));
    return;
    }
  }

