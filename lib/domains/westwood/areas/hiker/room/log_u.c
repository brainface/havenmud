#include <lib.h>
#include <climb.h>
inherit LIB_DUMMY;
inherit LIB_CLIMB;
#include "../hiker.h"

static void create() {
   dummy::create();
   SetKeyName("log");
   SetId( ({ "log" }) );
   SetShort("a fallen log");
   SetAdjectives( ({ "fallen","rotten","slightly" }) );
   SetLong("The fallen log is slightly rotten and bends a little "
           "under the weight of the years, but doesn't break or "
           "slide unter the water.  Instead, it stays nicely "
           "propped up against a wooden bridge that one could "
           "probably climb up onto.  Below is a fast moving "
           "stream.");
   SetClimb(H_ROOM + "trail_12",CLIMB_UP);
}
