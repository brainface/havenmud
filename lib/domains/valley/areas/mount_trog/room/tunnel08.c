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
  SetExits( ([
    "northwest" : TROG_ROOM "tunnel07",
    "south"     : TROG_ROOM "trog01",
    ]) );
  SetLong(
    "This tunnel is a small branch off the main east-west tunnel under Mount Trog. "
    "It appears to be a new excavation and not fully complete. To the south, the tunnel "
    "appears to be very un-gnomelike, with crude supports and a tiny stream of water "
    "running in a rivulet down the sides of the tunnel."
    );
  SetItems( ([
    ({ "support", "supports" }) : "The supports are very crude and poorly maintained.",
    ]) );
  SetInventory( ([
    TROG_OBJ "stream" : 1,
    ]) );
  SetSmell("A digusting smell comes from the south.");
  SetListen("A strange clacking noise comes from the south.");
}