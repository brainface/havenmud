/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../averath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("along a road in Averath");
  SetExits( ([
    "north" : AVERATH_ROOM "wharf",
    ]) );
  SetLong(
    "The road continues to the north, south, and east from here. To the west "
    "lies a small tavern. The view to the northeast is blocked by the shipping "
    "warehouse, but no entry can be seen from here. The paving stones of the "
    "road appear to be changed regularly, and the city has a well maintained "
    "look. It is apparent that the Grand Duchy of Averath is a prosperous "
    "land."
    );
  SetSmell("The scent of the sea drifts in from the north.");
  SetListen("Conversation seems to come from the south.");
  SetItems( ([
    "tavern" : "The tavern is clean and often busy.",
    ({ "road", "stone", "stones" }) : "The stones are clean and unbroken.",
    "warehouse" : "The warehouse is the shipping center of Averath.",
    ]) );
  SetEnters( ([
    "tavern" : AVERATH_ROOM "tavern",
    ]) );
}