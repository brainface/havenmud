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
   SetAdjectives( ({ "fallen","rotten" }) );
   SetLong("The log is slightly rotten, but seems to hold up well.  "
           "One could probably climb down on it from here on the bridge.");
   SetClimb(H_ROOM + "log",CLIMB_DOWN);
}
