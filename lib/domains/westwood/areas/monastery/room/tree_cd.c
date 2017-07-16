#include <lib.h>
#include <climb.h>
inherit LIB_DUMMY;
inherit LIB_CLIMB;
#include "../monastery.h"

static void create() {
   dummy::create();
    SetKeyName("tree");
   SetAdjectives( ({ "large","larger","thick","thicker","climbable",
                     "especially large" }) );
   SetShort("a tree trunk");
   SetLong("The trunk has many well-placed branches, so one could climb "
           "down it to safety easily.");
   SetClimb(M_ROOM + "plat_f",CLIMB_DOWN);
}
