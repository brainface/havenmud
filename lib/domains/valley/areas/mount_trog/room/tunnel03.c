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
    "west" : TROG_ROOM "tunnel02",
    "southeast" : TROG_ROOM "tunnel07",
    "northeast" : TROG_ROOM "tunnel04",
    ]) );
  SetLong(
    "The tunnel branches in several directions from here. Off to the "
    "west the tunnel leads back to the Underland. To the southeast "
    "the tunnel appears to be well supported and firmly designed, "
    "while to the northeast the tunnel appears to be more recently "
    "used."
    );
  SetInventory( ([
    TROG_NPC "rat" : 1,
    TROG_NPC "rat2": 1,
    ]) );
  SetSmell("The cave is damp and musty.");
  SetListen("The tunnel is very quiet this deep under the mountain.");
}