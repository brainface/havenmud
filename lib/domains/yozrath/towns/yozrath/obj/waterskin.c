/* a waterskin */
#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetShort("a skin of water");
  SetKeyName("waterskin");
  SetId( ({ "skin", "waterskin", "water" }) );
  SetAdjectives( ({ "water", "skin", "of" }) );
  SetLong("This leather skin is used to hold water. It sloshes as it moves.");
  SetMass(60);
  SetPortions(10);
  SetStrength(50);
  SetMealType(MEAL_DRINK);
  SetValue(30);
}
