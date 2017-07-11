#include <lib.h>
#include <meal_types.h>
void NukeMe();
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("chalice");
  SetId( ({"water","holy","holy chalice","chalice"}) );
  SetShort("a chalice of blessed water");
  SetMass(4);
  SetLong("This heavily ornamented chalice is filled with "
          "a blessed water from the heavens.  It looks very "
          "refreshing.");
  SetMealType(MEAL_DRINK);
  SetStrength(50);
  SetMealMessages("You drink from the chalice.","$N drinks from a "
                  "heavily ornamented chalice.");
  SetEmptyName("chalice");
  SetEmptyShort("an empty chalice");
  SetEmptyLong("This heavily ornamented chalice used to be filled "
               "with a blessed water.");
  call_out( "NukeMe", 20);
  }

void NukeMe() {
  if (environment())
   message("system", "A holy chalice dissappears.", environment() );
    eventDestruct();
   }

mixed eventDrink(object who) {
  remove_call_out( "NukeMe");
  meal::eventDrink(who);
  }
