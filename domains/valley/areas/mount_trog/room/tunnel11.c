/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include <domains.h>
#include "../trog.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in a tunnel under Mount Trog");
  SetClimate("underground");
  SetAmbientLight(15);
  SetExits( ([
    "east" : CRYSTAL_REACHES_VIRTUAL "glimmerdintunnel/0,0",
    "west" : TROG_ROOM "tunnel10",
    ]) );
  SetLong(
    "The tunnel opens here to a wider tunnel which at one point "
    "must have been more heavily used. To the east the tunnel "
    "has walls which appear to have been well-mined and are "
    "supported and smooth. To the west the tunnel falls into "
    "more immediate disrepair."
    );
  SetSmell("The cave is damp and musty.");
  SetListen("The tunnel is very quiet this deep under the mountain.");
}