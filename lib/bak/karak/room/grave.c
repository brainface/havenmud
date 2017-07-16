#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
room::create();
SetShort("Creepy Cemetary");
  SetObviousExits("out");
SetExits( ([
                  "out" : K_ROOM + "/rd6" ]) );
  SetDayLong("This place is a bit spooky even during the day. "
                "Small mounds of dirt mark the final resting "
                "places of the deceased.  Row upon row of such "
                "mounds suggest that Karak-Varn is a violent "
                "place to live.  High and sturdy walls border this "
                "area to the north, west, and south, and a small dirt "
                "path leads back into the city to the east.");
  SetNightLong("The wind whips violently through the area, which is "
               "filled with long, dark rows of burial mounds.  The "
               "welcoming sights and sounds of civilization are just to "
               "the east of here.");

}
