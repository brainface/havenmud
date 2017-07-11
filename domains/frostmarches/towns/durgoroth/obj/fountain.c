#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("fountain");
  SetPreventGet("The fountain is much too large to move.");
  SetMealType(MEAL_DRINK);
  SetMealMessages("You drink from the blood fountain.",
                  "$N drinks from the fountain of blood.");
  SetStrength(80);
  SetId( ({ "fountain" }) );
  SetShort("a large fountain of blood");
  SetAdjectives( ({ "large", "blood" }) );
  SetPortions(-1);
  SetLong("This fountain is very ugly. It has been"
          " crafted from a dark stone, possibly obsidian"
          " and it has a spout in the center that sprays"
          " blood into the air.");
}

int eventDrink(object who) {
  if (who->GetRace() != "daemon" && who->GetRace() != "nosferatu") {
    who->eventPrint("Drinking blood is not in your best interest.");
    return 0;
  } 
   return (meal::eventDrink(who));
}

  
