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
    "east" : TROG_ROOM "tunnel03",
    "west" : TROG_ROOM "tunnel01",
    ]) );
  SetLong(
    "The tunnel continues to the east and west from here. To the east, the tunnel "
    "seems to branch off in different directions. To the west, the tunnel leads "
    "back to the surface of the Underland. Faint scratches line the base of the "
    "tunnel, suggesting that the rodent menace continues deeper into the tunnel."
    );
  SetInventory( ([
    TROG_NPC "rat2" : 2,
    ]) );
  SetSmell("The cave is damp and musty.");
  SetListen("The tunnel is very quiet this deep under the mountain.");
}