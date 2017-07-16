#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("heart");
  SetId( ({ "heart" }) );
  SetShort("a bloodied unicorn heart");
  SetAdjectives( ({ "unicorn", "bloodied" }) );
  SetLong("Still dripping with blood, this heart is fresh"
          " and free of any signs of rotting. It is quite"
          " large and heavy. The unicorn it was taken from"
          " must have been young and healthy.");
  SetProperty("magic", "if one were evil enough to do so,"
            " this heart can be ate. Unicorn hearts are"
            " known to have similar healing properties"
            " of unicorn horns.");
  SetMealType(MEAL_FOOD);
  SetStrength(25);
  SetValue(5500);
  SetMass(35);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_MAGIC);
}

int eventEat(object who) {
  if(who->GetMorality() <= -1000) {
  who->eventCompleteHeal(500);
  who->eventMoralAct(-100);
  return (meal::eventEat(who));
   }
  who->eventCompleteHeal(500);
  who->eventMoralAct(-500);
  message("system", "You feel as though you've done a horrible thing.", environment());
  return (meal::eventEat(who));
}
