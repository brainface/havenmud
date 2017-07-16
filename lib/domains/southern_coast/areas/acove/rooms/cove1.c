/* entrance to cove
   zara 7/26/98
*/

#include <lib.h>
#include <domains.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a sandy trail");
  SetClimate("temperate");
  SetExits( ([
          "south" : ACOVE_ROOMS + "cove2",
          "north" : SOUTHERN_COAST_VIRTUAL "havenroad/20,0",
           ]) );
  SetLong("Grass grows sparsely here in the sandy soil. "
          "There seems to be a faint outline of a path ahead  "
          "but it looks unused and choked by weeds.  Clusters  "
          "of strange vines grow profusely, discouraging  "
          "passage.  It is as if a subtle warning has been  "
          "issued to any who dare to enter here."
          "  A major roadway lies to the north.");
  SetItems( ([
          "grass" : "This grass is tall and reed-like.",
          ({ "major roadway", "major road", "road", "roadway"}) :
          "The roadway a short distance to the north appears to be none "
          "other than the great Haven road.",
          ({ "sandy soil", "soil", "sand" }) : "This soil is "
                                             "light-colored and "
                                             "mixed with sand.",
          ({ "outline", "path" }) : "This outline is very faint "
                                    "but seems to some kind of "
                                    "path.",
          ({ "weed", "weeds" })  : "Various hardy weeds grow "
                                   "profusely here, making "
                                   "travel difficult.",
          ({ "cluster", "clusters", "vine", "vines" }) : "The shiny green "
                                                         "vines here have "
                                                        "the appearance of "
                                                       "snakes moving through "
                                                       "the grass.",
         ({ "snake", "snakes" }) : "These are actually vines "
                                   "blocking the path.",
         ]) );
  SetItemAdjectives( ([
   "grass" : ({"tall","reed-like"}),
    "sandy soil" : ({ "light-colored", "light" }),
    "weed" : ({"hardy","profuse"}),
    "vine" : ({"green","shiny"}),
   "outline" : ({"faint"}),
     ]) );
  SetInventory( ([
       ]) );
}
