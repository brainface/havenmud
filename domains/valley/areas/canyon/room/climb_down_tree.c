#include <lib.h>
#include <climb.h>
#include "../jidnewbi.h"
inherit LIB_DUMMY;
inherit LIB_CLIMB;

static void create() {
   dummy::create();
  SetKeyName("tree");
   SetAdjectives( ({ "large","principle" }) );
   SetShort("a large tree");
   SetLong("The tree grows tall and furious.  It looks like it would "
           "be easy to climb down it.");
   SetClimb(JD_ROOM + "/tree_bottom",CLIMB_DOWN);
}



/* Approved by Zaxan on Sat Jan 17 03:23:24 1998. */
