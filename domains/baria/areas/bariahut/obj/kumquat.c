//Alex@Haven
//2006
#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create(){
  ::create();
  SetKeyName("kumquat");
  SetShort("a squishy kumquat");
  SetId( ({ "kumquat", "fruit" }) );
  SetAdjectives( ({ "squishy" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetLong(
    "This is a squishy orange kumquat, a meal fit "
    "for a jungle king. Or maybe a jungle duke.");
  SetSmell( "It smells amazingly tangy and sweet." );
  SetMealMessages("The kumquat is sweet and tangy.",
      "$N eats a squishy kumquat.");
}
