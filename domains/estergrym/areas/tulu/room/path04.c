/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../tulu.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("along a path up a hill");
  SetExits( ([
    "north" : TULU_ROOM "path05",
    "south" : TULU_ROOM "path03",
    ]) );
  SetLong(
    "The path continues to the north and south. "
    "The base of the hill rises directly to the north, and it is obvious that from here "
    "continuing would require a slight climb. "
    "From this distance, nothing about the "
    "top of the hill can be determined. The Estergrym Mountains rise far to the east from here."
    );
  SetSmell("The breeze from the Estergrym Mountains is not as pronounced here.");
}