/*  center hall */

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(45);
  SetShort("the center of Glistendin");
  SetLong("It is here that the both the "
    "passages converge upon the Great Hall. The Great Hall is "
    "vast beyond comprehension, and its ceiling towers high "
    "into the air and holds the unimaginable weight of the very "
    "mountain at bay; it is a testament to the dwarven cunning "
    "and craftsmanship, for no other mortal structure could ever "
    "be of such magnitude. The enormous archway leading into "
    "the Church of Kylin stands to the south. The Church dominates the "
    "entire great hall with its massive presence. A spiraling ramp "
    "up into the mountain leads to the great forges and armories "
    "of Glistendin while the eastern leads back to the exit tunnel. "
    "Lying embedded into the western wall is an ornately carved building "
    "which seems to function as a government office.");
  SetItems( ([
    ({"hall","great hall", "Great Hall", "great hall of the dwarves",
      "Great Hall of the Dwarves", "ceiling", "structure", "mountain"}) :
      "The Great Hall of the Dwarves is cut from the stone of the "
      "mountain and is immeasurably large, both in width and "
      "height especially.  Its ceiling towers high and supports the "
      "unimaginable weight of the mountain itself.",
    ({"church","church of kylin",
      "Church of Kylin", "archway" }) : "The Church of Kylin, "
      "in all its glory, is to the south.",
    ({ "building", "office" }) : 
      "The ornately carved building seems to function as a Clan Hall.",
    ({"eastern passage", })  :
      "The tunnel leading back to the plains of Averath lies east.",
    ]) );
  SetItemAdjectives( ([
    "hall"  :  ({ "massive", "enormous", "immense", "huge"}),
    "church"  :  ({"massive", "enormous", "immense", "huge",
                   "dominating", }),
    "building" : ({ "ornately", "carved" }),               
    ]) );
  SetExits( ([
    "south" : AVERATH_ISLAND "-8,-4,0",
    "east"  : AVERATH_ISLAND "-7,-3,0",
    "up"    : AVERATH_ISLAND "-8,-3,1",
    ]) );
  SetEnters( ([
    "building" : G_ROOM "office",
    ]) );
  SetSmell( ([
    "default" : "Smoke is very faint here.",
    ]) );
  SetListen( ([
    "default" : "Dwarven voices can be heard to the south.",
    ]) );
  SetInventory( ([
    G_OBJ "fountain" : 1,
    G_NPC "rat_vendor" : 1,
    ]) );
}
