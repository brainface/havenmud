//Alex@Haven
//2006
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create(){
  meal::create();
  SetKeyName("wine");
  SetId( ({ "bottle", "wine", "bottle of wine", "kumquat" }) );
  SetAdjectives( ({"homemade", "empty"}) );
  SetShort("a bottle of homemade kumquat wine");
  SetMass(25);
  SetValue(1);
  SetLong(
    "This bottle is filled with orange-coloured sweet "
    "wine, made from kumquat fruits.");
  SetSmell ( ([
    "wine" : "Smells like a hangover to me.",
  ]) );
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(50);
  SetMealMessages("You drink the bottle of homemade kumquat wine.",
    "$N drains a bottle of homemade kumquat wine. What a lush.");
  SetEmptyName("bottle");
  SetEmptyShort("an empty wine bottle");
  SetEmptyLong("This is an empty wine bottle. It smells fruity.");
}
