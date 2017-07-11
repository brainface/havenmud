/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../trog.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a tunnel under Mount Trog");
  SetClimate("underground");
  SetAmbientLight(15);
  SetExits( ([
    "east" : TROG_ROOM "tunnel02",
    "west" : TROG_ROOM "entrance",
    ]) );
  SetLong(
    "The tunnel continues deeper under Mount Trog from here. Directly to the west "
    "is the entrance to these tunnels and the exit back into the Underland. As the "
    "tunnel continues east, it slowly descends into the bowels of the mountain. "
    "Small scratches can be seen near the base of the tunnel."
    );
  SetItems( ([
    ({ "scratch", "scratches" }) : "The scratches are small claw marks from a rodent.",
    ]) );
  SetSmell("The cave is damp and musty.");
  SetListen("The tunnel is very quiet this deep under the mountain.");
  SetInventory( ([
    TROG_NPC "rat" : 2,
    ]) );
}