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
    "east" : TROG_ROOM "tunnel06",
    "southwest" : TROG_ROOM "tunnel04",
    ]) );
  SetLong(
    "This section of the mine is obviously abandoned. Small cobwebs "
    "are attached all over the mine shaft, and the support beams are "
    "literally coated in webbing. To the southwest the tunnel leads "
    "back towards the main vein of the path under Mount Trog, while "
    "to the east the tunnel seems eerie and less friendly."
    );
  SetSmell("The cave is damp and musty.");
  SetListen("The tunnel is very quiet this deep under the mountain.");
}