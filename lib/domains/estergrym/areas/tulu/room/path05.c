/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../tulu.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("climbing a path up a hill");
  SetExits( ([
    "north" : TULU_ROOM "path06",
    "south" : TULU_ROOM "path04",
    ]) );
  SetLong(
    "The path continues to climb the hill from this point. To the south, the path "
    "trails off towards the base of the hill. From here, the top of the hill is barely "
    "visible, and it appears that some stone structures may exist upon it. Almost no "
    "vegetation seems to grow here, not even the scrubgrass that should exist upon a "
    "hill of this size."
    );
  SetSmell("A faint odor seems to eminate from the hill.");
}