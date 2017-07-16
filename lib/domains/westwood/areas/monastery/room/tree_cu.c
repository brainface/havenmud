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
   SetShort("an especially large tree");
   SetLong("This trunk is large than the others here, and is attached "
           "right to the platform.  Tree branches come out at nice "
           "angles in convienent spots, making it possible to climb up "
           "to a branch that is above and on the other side of the "
           "trunk, larger than the others.");
   SetClimb(M_ROOM + "branch",CLIMB_UP);
}
