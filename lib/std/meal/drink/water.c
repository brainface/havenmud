#include <lib.h>
#include <meal_types.h>
void NukeMe();
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("water");
  SetShort("a cup of water");
  SetMass(5);
  SetLong("This cup of water has been magically created.  The "
          "water in it looks very refreshing.  Mabye you should "
          "<drink> it?.");
  SetMealType(MEAL_DRINK);
  SetStrength(50);
  SetMealMessages("You drink the water.","$N drinks the water.");
  SetEmptyName("cup");
  SetEmptyShort("an empty cup");
  SetEmptyLong("This is an empty cup.");
  call_out( "NukeMe", 20);
  }

 void NukeMe() {
  if (environment())
   message("system", "A cup of water disintegrates.", environment() );
    eventDestruct();
   }

mixed eventDrink(object who) {
  remove_call_out( "NukeMe");
  meal::eventDrink(who);
  }
