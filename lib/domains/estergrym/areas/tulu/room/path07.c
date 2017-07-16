/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../tulu.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("climbing a path near the top of a hill");
  SetExits( ([
    "north" : TULU_ROOM "path08",
    "south" : TULU_ROOM "path06",
    ]) );
  SetLong(
    "The path continues to climb the hill from this point. To the south, the path "
    "trails off towards the base of the hill. This point seems to be "
    "near to the top of the hill. From here it is obvious that there are "
    "structures of some kind upon the rise of the hill. Almost no "
    "vegetation seems to grow here, not even the scrubgrass that should exist upon a "
    "hill of this size."
    );
  SetSmell("An evil odor seems to eminate from the hill.");
}