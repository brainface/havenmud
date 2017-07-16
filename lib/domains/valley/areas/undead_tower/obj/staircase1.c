//    Coded by Severen    //
//      staircase1.c      //
//     Nov. 7th 1998      //


#include <lib.h>
#include <climb.h>
#include "../defs.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
    item::create();
    SetKeyName("staircase");
    SetId( ({ "staircase","stairs","steps" }) );
    SetShort("a staircase");
    SetLong("This is the lower end of a magnificent staircase. It looks as "
      "if it was carved out of the walls themselves. It leads up and down. "
      "It looks very old and caution should be used climbing it. There is "
      "a door higher up the staircase.");
    SetAdjectives(({"magnificent","old","stone","carved"}));
    SetClimb(TROOM + "/stair2",CLIMB_UP);
    SetClimb(TROOM + "/hall",CLIMB_DOWN);
    SetPreventGet("You cannot get a staircase.");
}
