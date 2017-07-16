//    Coded by Severen    //
//      staircase4.c      //
//     Nov. 7th 1998      //


#include <lib.h>
#include <climb.h>
#include "../defs.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
    item::create();
    SetId( ({ "staircase","stairs","steps" }) );
    SetShort("a staircase");
    SetLong("This is a lower end of a magnificent staircase. It looks as "
      "if it was carved out of the walls themselves. It leads up and down. "
      "It looks very old and caution should be used climbing it. There is "
      "a door above and below on the staircase. It's a long drop to the "
      "bottom floor.");
    SetAdjectives(({"magnificent","old","stone","carved"}));
    SetClimb(TROOM + "/stair5",CLIMB_UP);
    SetClimb(TROOM + "/stair3",CLIMB_DOWN);
    SetPreventGet("You cannot get a staircase.");
}
