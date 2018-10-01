#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("whiskey");
  SetId( ({ "whiskey", "jar" }) );
  SetAdjectives( ({ "whiskey", "whiskey in the" }) );
  SetShort("whiskey in the jar");
  SetMass(15);
  SetValue(0);
  SetLong(
    "This is a small jar, which appears to be carved out of grey "
    "stone. A stopper is jammed in to it narrow neck, holding in "
    "whatever is inside. Carvings along the side of the jar seem "
    "to indicate that it contains whiskey."
  );
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(50);
  SetPortions(5);
}

void init() {
  ::init();
  add_action("drink", "drink");
}

int drink(string args) {
  if(args != "whiskey") {
    return 0;
  }
  message(
    "my_action", "You feel an overwhelming urge to sing!",
    this_player());
  message(
    "other_action", this_player()->GetName() + "drinks blah "
    "and bursts in to song!",
    environment(this_player()), this_player());
return 1;
}
