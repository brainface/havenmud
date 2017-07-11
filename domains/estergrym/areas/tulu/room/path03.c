/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../tulu.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("along a desolate path");
  SetExits( ([
    "north" : TULU_ROOM "path04",
    "southeast" : TULU_ROOM "path02",
    ]) );
  SetLong(
    "The path continues to the north and southeast. To the southeast, the path winds "
    "down to the North Road which stretches along the eastern seaboard of Kailie's main continent. "
    "To the north, the path marches toward a hill. From this distance, nothing about the "
    "top of the hill can be determined. The Estergrym Mountains rise far to the east from here."
    );
  SetSmell("The breeze from the Estergrym Mountains is not as pronounced here.");
}