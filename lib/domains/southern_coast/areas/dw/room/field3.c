#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an empty field");
  SetDayLong("The sunlit fields of wasteland are barren and desolate "
            "with no features of any beauty what so ever.  To the east "
            "and south there is a structure of stone which rises out "
            "of the ground as if to reach for the sun itself.");
  SetNightLong(
              "The starlit fields of the old cemetery are empty and devoid of "
               "life of any kind.  To the south and east there is a "
               "structure which rises in an attempt to grasp the stars "
               "and drag them to its level.");
  SetItems( ([
     "structure" : "The stone construct is an ancient crypt.",
    ]) );
  SetSmell( ([
     "default" : "The odor of decayed flesh rises into the air.",
    ]) );
  SetListen( ([
     "default" : "There is an unnerving silence in the air.",
     ]) );
  SetDayLight(-10);
  SetExits( ([
     "south" : NEWBIE_ROOM + "/field2",
     "east"  : NEWBIE_ROOM + "/field6",
     ]) );
  }
