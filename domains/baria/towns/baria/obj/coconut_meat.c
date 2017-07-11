//
//  Summary: Coconut meat to eat
//  Created by Rhakz - Angel Cazares
//  For Baria
//  Date: 10/14/98
//
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("coconut meat");
  SetShort("a bowl of coconut meat");
  SetMass(25);
  SetId( ({"meat","coconut","coconut meat"}) );
  SetLong("A bowl full of fresh coconut meat.");
  SetMealType(MEAL_FOOD);
  SetStrength(50);
  SetMealMessages(
                  "You feel refreshed.", 
                  "$N eats some coconut meat."
                 );
}
