//
// A small cup of water
// Created by Athalie
//
#include <lib.h>
#include "../bazaar.h"
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
   SetKeyName("cup of water");
   SetId( ({ "water", "cup", "cup of water" }) );
   SetShort("a cup of water");
   SetLong("This small cup is filled to the brim with room temperature "
     "drinking water. There are very few dirt particles in it, however, so "
     "it's probably quite safe to drink.");
   SetMass(5);
   SetMealType(MEAL_DRINK);
   SetStrength(75);
   SetMealMessages("You feel amazingly refreshed after drinking the water.",
     "$N drinks a cup of water.");
   SetEmptyName("cup");
   SetEmptyShort("an empty cup");
   SetEmptyLong("This plain cup is empty.");
   SetEmptyName("cup");
}
