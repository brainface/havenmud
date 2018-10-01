//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>

#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();

  switch(random(4)) {

    case 0:
      SetKeyName("orange");
      SetId( ({ "orange" }) );
      SetAdjectives( ({ "sweet" }) );
      SetShort("a sweet orange");
      SetMass(15);
      SetLong(
        "The round orange is fleshy and sweet."
      );
      SetMealType(MEAL_FOOD);
      SetStrength(10);
      SetPortions(10);
      SetMealMessages(
        "You eat a slice of orange.",
        "$N eats a slice of orange."
      );
    break;

    case 1:
      SetKeyName("truffle");
      SetId( ({ "truffle" }) );
      SetAdjectives( ({ "black" }) );
      SetShort("a black truffle");
      SetMass(5);
      SetLong(
        "A truffle is the fruiting body of a subterranean fungus."
      );
      SetMealType(MEAL_FOOD);
      SetStrength(15);
      SetPortions(1);
      SetValue(25);
      SetMealMessages(
        "You eat a black truffle.",
        "$N eats a black truffle."
      );
    break;

    case 2:
      SetKeyName("coconut meat");
      SetShort("a bowl of coconut meat");
      SetMass(25);
      SetId( ({"meat","coconut","coconut meat"}) );
      SetLong("A bowl full of fresh coconut meat.");
      SetMealType(MEAL_FOOD);
      SetStrength(20);
      SetMealMessages(
        "You feel refreshed.", 
        "$N eats some coconut meat."
      );
    break;

    case 3:
      SetKeyName("apple");
      SetId( ({"apple"}) );
      SetAdjectives( ({"small", "shiny"}) );
      SetShort("a small shiny apple");
      SetLong(
        "This is a small shiny apple, it doesn't look like it would be very"
        "filling."
      );
      SetMealType(MEAL_FOOD);
      SetStrength(5);
      SetPortions(2);
      SetMass(3);
      SetMealMessages(
        "You bite into an apple.",
        "$N bites into an apple.",
      );
    break;
  }
}


