// Dalnairn
// Aerelus

#include <lib.h>
#include <meal_types.h>
#include "../dalnairn.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fountain");
  SetId( ({"fountain"}) );
  SetShort("a tall fountain");  
  SetLong(
    "This tall fountain provides a free supply of water to passers by. Fed "
    "directly from an underground source, the water looks very fresh."
  );
  SetAdjectives( ({ "tall" }) );
  
  SetMealType(MEAL_DRINK);
  SetPreventGet("You may find that hard to carry.");
  SetPortions(-1);
  SetStrength(45);
  SetMealMessages( ({ 
    "$N sip from a tall fountain. The water is very refreshing.", 
    "$N sips from the tall fountain.",
  }) );
}
