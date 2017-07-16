/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../tulu.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("atop a hill with a stone henge");
  SetLong(
    "The circle of stone extends in a circle to the west and north. "
    "In the center of the circle, to the northwest, lies a huge stone altar. "
    "The soil around "
    "the altar and the henge is blackened and charred, and no plant life exists "
    "within easily 50 yards of the top of the hill."
    );
  SetItems( ([
    "altar" : "The altar sits in the center of the henge. From here, it appears that "
              "the altar has some form of gap in its center.",
    ({ "stone", "stones", "henge", "circle" }) : "The stones surround the "
              "altar, forming a perfect circle.",
    "path" : "The path leads to the south and down the hill.",
    ]) );
  SetExits( ([
    "west"  : TULU_ROOM "hill01",
    
    "north" : TULU_ROOM "hill04",
    ]) );
  SetSmell("The rotting meat smell seems to come from the northwest.");
  SetInventory( ([
    TULU_NPC "cultist_priest" : random(2),
    TULU_NPC "cultist_fighter": random(2),
    ]) );      
}