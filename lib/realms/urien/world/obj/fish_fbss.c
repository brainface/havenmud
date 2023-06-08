// A silver-sqkien bass sold by the Soliel fisherbear
// Urien@Haven 08JUN2023

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("bass");
  SetShort("a silver sqkien bass");
  SetStrength(60);
  SetMass(20);
  SetId( ({ "bass", "sqkien" }) );
  SetAdjectives( ({"silver","sqkien"}) );
  SetLong("This silver bass has small and tight scales that hug the "
          "meaty adult body from mouth to tail. Most of the bass "
          "has been prepped for immediate consumption by having the "
          "fins and eyes removed. It looks to be a decent portion, "
          "enough to satiate a hunters hunger for a brief moment. "
          "The silver skin is a main feature of this bass and the "
          "meat itself looks fresh with natural juices.");
  SetMealMessages( ({
    "$N consumes the silver-sqkien bass.",
    "You eat the silver-sqkien bass, it has a light flavor and delicate texture.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(16);
}
