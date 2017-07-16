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
    "The circle of stone extends in a circle to the north and south. "
    "In the center of the circle, to the west, lies a huge stone altar. "
    "The soil around "
    "the altar and the henge is blackened and charred, and no plant life exists "
    "within easily 50 yards of the top of the hill."
    );
  SetItems( ([
    "altar" : "The altar sits in the center of the henge. From here, it appears that "
              "the altar has some form of gap in its center.",
    ({ "stone", "stones", "henge", "circle" }) : "The stones surround the "
              "altar, forming a perfect circle.",
    ]) );
  SetExits( ([
    "west"  : TULU_ROOM "hill03",
    "south" : TULU_ROOM "hill09",
    "north" : TULU_ROOM "hill05",
    ]) );
  SetSmell("The rotting meat smell seems to come from the west.");
  SetInventory( ([
    TULU_NPC "cultist_priest" : random(2),
    TULU_NPC "cultist_fighter": random(2),
    ]) );
}