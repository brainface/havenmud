//
// Cooked meat on a stick
// Created by Athalie
//
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
   SetKeyName("stick of skewered meat");
   SetId( ({ "stick", "meat", "stick of meat", "stick of skewered meat" }) );
   SetShort("a stick of skewered meat");
   SetLong("This is a long wooden stick on which several pieces of well-"
     "cooked meat have been skewered.");
   SetMealType(MEAL_FOOD);
   SetStrength(75);
   SetMass(15);
   SetMealMessages("You gobble down several pieces of meat as you pull them "
     "from the skewer.",
     "$N gobbles down several pieces of meat from a skewer.");
}
