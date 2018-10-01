//
// Summary: Meat for the inn
// Created by Rhakz - Angel Cazares
// Date: 10/14/98
//
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("monkey meat");
  SetShort("a well-done chunk of monkey meat");
  SetMass(15);
  SetId( ({"meat","chunk","monkey meat","chunk of monkey meat","well-"
           "done chunk of money meat",}) );
  SetAdjectives( ({"well-done","large"}) );
  SetLong("This large chunk of monkey meat smells really nice. "
          "Hopefully it tastes as good as it smells.");
  SetMealType(MEAL_FOOD);
  SetStrength(35);
  SetMealMessages(
                  "You gobble up the chunk of monkey meat.", 
                  "$N eats a chunk of monkey meat."
                 );
  }

