/* Duhoc Jan. 99 */
/* based on fact that dwarves can handle more ale*/

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

void CheckDwarf();

static void create()
{
  meal::create();
  SetKeyName("ale");
  SetId( ({ "mug","ale" }) );
  SetAdjectives( ({ "dark ale" }) );
  SetShort("a mug of dark ale");
  SetMass(10);
  SetValue(2);
  SetLong("This is a frothy mug of dark ale.");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  call_out((: CheckDwarf :), 0);
  SetMealMessages("You down a mug of ale.",
                  "$N downs a mug of ale.");
  SetEmptyName("mug");
  SetEmptyShort("an empty mug");
  SetEmptyLong("This is an empty mug.");
}

void CheckDwarf() {
  if( (string)this_player()->GetRace() == "dwarf" ) {
    SetStrength(5);
  } else {
    SetStrength(25);
  }
}
