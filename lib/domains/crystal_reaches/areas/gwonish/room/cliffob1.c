#include <lib.h>
#include <climb.h> 
#include "../path.h"

inherit LIB_DUMMY; 
inherit LIB_CLIMB;

static void create() {
    dummy::create();
    SetId("cliff");
    SetShort("a cliff");
    SetLong("Towering nearly 200 feet above you the cliff is composed mainly "
            "of earth with roots sticking out periodically.");
    SetClimb(GWONISH + "room/path4", CLIMB_UP);
}
