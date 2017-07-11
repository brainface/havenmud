#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
void NukeMe();
int life = 30;

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
  SetValue(0);
  SetMealMessages("You drink the water.","$N drinks the water.");
  SetEmptyName("cup");
  SetEmptyShort("an empty cup");
  SetEmptyLong("This is an empty cup.");
  set_heart_beat(1);
}

void heart_beat() {
   life--;
   if(!life) { NukeMe(); }
}

 void NukeMe() {
  if (environment())
   message("system", "A cup of water disintegrates.", environment() );
    eventDestruct();
   }

mixed eventDrink(object who) {
  life = -1;
  meal::eventDrink(who);
  }
