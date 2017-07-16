#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("monkey meat");
  SetId( ({ "meat"}) );
  SetAdjectives( ({ "monkey" }) );
  SetShort("a scrap of monkey meat");
  SetMass(1);
  SetLong("This is a small scrap of monkey meat. It looks"
          " rather tough and gamey.");
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetPortions(8);
  SetMealMessages(
    "You eat a scrap of monkey meat.",
    "$N eats a scrap of monkey meat.");
}


int eventEat() {
    this_player()->eventPrint("There is not even enough meat"
                " to satisfy you. Save it for something else.");
    return 0;
}

