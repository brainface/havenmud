
/* faerie ring
    Ela 12/5/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a shimmering void");
  SetClimate("temperate");
  SetObviousExits("There is no way out! You're a prisoner of the Fae!");
  SetLong("Walls of shimmering light and blurred color "
          "envelope the room. Directionless and confusing "
         "it is difficult to find one's bearings. "
         "The walls pulse with magic and there are no "
         "visible exits from the fae's clever trap. "
         "The mercy of the gods is the only hope of "
         "salvation.");
  SetItems( ([
       ({"wall","walls"}) : "They seem to undulate and pulse, "
                            "shimmering with magic and "
                            "flashes of incandescent color.",
      ({"void","trap"}) : "The void is disorienting but "
                          "quite beautiful, despite its "
                          "being a trap.",
      ]) );
  SetProperty("no teleport", 1);
}
