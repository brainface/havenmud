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
    "northwest" : TULU_ROOM "path03",
    "southeast" : TULU_ROOM "path01",
    ]) );
  SetLong(
    "The path continues to the northwest and southeast. To the southeast, the path meets "
    "up with the North Road which winds along the eastern seaboard of Kailie's main continent. "
    "To the northwest, the path marches toward a hill. From this distance, nothing about the "
    "top of the hill can be determined. The Estergrym Mountains rise far to the east from here."
    );
  SetSmell("The breeze from the Estergrym Mountains is not as pronounced here.");
}