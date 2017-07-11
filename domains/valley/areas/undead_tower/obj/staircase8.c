//    Coded by Severen    //
//      staircase8.c      //
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
    SetLong("This is the highest part of a magnificent staircase. It "
      "looks as if it was carved out of the walls themselves. It leads down "
      "from here. It looks very old and caution should be used climbing down "
      "it. There is a door here and one further down the staircase. It is "
      "an extremely long drop to the bottom floor.");
    SetAdjectives(({"magnificent","old","stone","carved"}));
    SetClimb(TROOM + "/stair7",CLIMB_DOWN);
    SetPreventGet("You cannot get a staircase.");
}
