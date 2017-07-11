/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../thra.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "down" : THRA_EXIT,
    "north": THRA_ROOM "n",
    "south": THRA_ROOM "s",
    "west" : THRA_ROOM "w",
    "east" : THRA_ROOM "e",
    "northeast" : THRA_ROOM "ne",      
    "northwest" : THRA_ROOM "nw",
    "southeast" : THRA_ROOM "se",
    "southwest" : THRA_ROOM "sw",
    "up"        : THRA_ROOM "cemetery",
    ]) );
  SetShort("the center of the Village of Thra");
  SetLong(
    "This raised platform above the Westwood houses the Village of Thra, the home of "
    "Gelfling life on Kailie. Though smaller than the gelflings original home, this village "
    "has become the de facto capital of all gelflings after their flight from the Havenwood. "
    "The platform leads off in several directions from here, with smaller offshoots in most "
    "directions."
    );
  SetInventory( ([
    THRA_NPC "guard" : 2,
    ]) );
  
}