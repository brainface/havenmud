/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../trog.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in a tunnel under Mount Trog");
  SetClimate("underground");
  SetAmbientLight(15);
  SetExits( ([
    "northeast" : TROG_ROOM "tunnel05",
    "southwest" : TROG_ROOM "tunnel03",
    ]) );
  SetLong(
    "The tunnel heads northeast and southwest from here. Off to the "
    "northeast the tunnel seems to be less well traveled. Directly "
    "to the southwest is a small fork in the tunnel which leads "
    "west to the Underland and southeast deeper into the mines."
    );
  SetSmell("The cave is damp and musty.");
  SetListen("The tunnel is very quiet this deep under the mountain.");
}
