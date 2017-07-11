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
    "east" : TROG_ROOM "tunnel09",
    "northwest" : TROG_ROOM "tunnel03",
    "southeast" : TROG_ROOM "tunnel08",
    ]) );
  SetLong(
    "The tunnel continues to the east from here and back to the northwest. A smaller tunnel "
    "heads off to the southeast. The southeast passage is still shakily "
    "supported by temporary girders and appears to be a newer dig. "    
    );
  SetItems( ([
    ({ "girder", "girders" }) : "The girders on the southeast passage are new "
                                "and seem very temporary in nature.",
    ]) );
  SetInventory( ([
    TROG_OBJ "pool" : 1,
    ]) );
  SetSmell("The cave is damp and musty.");
  SetListen("The tunnel is very quiet this deep under the mountain.");
}
