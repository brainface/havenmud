/* path to beach
   Zara 7/28/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
 room::create();
 SetShort("a clearer path");
 SetClimate("temperate");
 SetExits( ([
         "south" : ACOVE_ROOMS + "cove3",
         "north" : ACOVE_ROOMS + "cove1",
          ]) );
 SetLong("The faint path widens slightly here and is more "
         "distinct.  The grass and vines are less dense. "
         "The soil is sandier than it was before.  "
         "Smooth, polished rocks are scattered along the way.");
 SetItems( ([
         "path"  : "The path shows some signs of wear.",
         "grass" : "This grass is tall and reed-like.",
         "sand"  : "The sand here is fine and white.",
         ({ "vine", "vines" })  : "The shiny green vines here "
                                  "have the appearance of snakes "
                                  "moving through the grass.",
         ({ "rock", "rocks" })  : "These rocks are black and smooth.",
         "soil" : "The soil here is very sandy.",
        ({"snake", "snakes" }) : "These are actually vines "
                                  "blocking the path.",
        ]) );
 SetItemAdjectives( ([
  "path" : ({"distinct","faint","wider"}),
 "grass" : ({"tall","reed-like","sparse"}),
  "sand" : ({"white","fine"}),
  "vine" : ({"shiny","snake-like","sparse"}),
  "soil" : ({"light-colored","light","sandy"}),
   ]) );

}
