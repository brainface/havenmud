//    Coded by Severen    //
//      staircase.c       //
//     Nov. 7th 1998      //


#include <lib.h>
#include <climb.h>
#include "../defs.h"
inherit LIB_DUMMY;
inherit LIB_CLIMB;

static void create() {
    dummy::create();
    SetKeyName("staircase");
    SetId( ({ "staircase","stairs","steps" }) );
    SetShort("a staircase");
    SetLong("A magnificent work of craftsmanship, the staircase looks as "
      "if it was carved out of the walls themselves. It does look "
      "very old and caution should be used climbing it. A door can be seen "
      "higher up the staircase.");
    SetAdjectives(({"magnificent","old","stone","carved"}));
    SetClimb(TROOM + "/stair1",CLIMB_UP);
}
