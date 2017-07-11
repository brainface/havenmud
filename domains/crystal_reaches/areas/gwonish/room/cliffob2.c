#include <lib.h>
#include <climb.h> 
#include "../path.h"

inherit LIB_ITEM; 
inherit LIB_CLIMB;

static void create() {
    item::create();
    SetId("cliff");
    SetShort("a gigantic cliff");
  SetKeyName("cliff");
  SetInvis(1);
    SetLong("Towering nearly 150 feet above you the cliff is composed mainly "
            "of earth with roots sticking out periodically.");
    SetClimb(GWONISH + "room/path5", CLIMB_UP);
}
