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
    "east" : TROG_ROOM "tunnel10",
    "west" : TROG_ROOM "tunnel07",
    ]) );
  SetLong(
    "The tunnel continues to the east and west from here. Heavy support beams maintain "
    "this tunnel, and it is obvious that this tunnel was well-trafficked at some point. "
    "The tunnel appears to get wider as it continues east. Off to the west there is a "
    "small branch-off tunnel."
    );
  SetSmell("The cave is damp and musty.");
  SetListen("The tunnel is very quiet this deep under the mountain.");
}