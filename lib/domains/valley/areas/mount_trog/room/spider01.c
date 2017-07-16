/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../trog.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in a foul smelling burrow");
  SetClimate("underground");
  SetExits( ([
    "north" : TROG_ROOM "tunnel08",
    "east"  : TROG_ROOM "trog03",
    "west"  : TROG_ROOM "trog02",
    ]) );
  SetLong(
    "The tunnel opens here to a foul-smelling burrow. The area is littered "
    "with small piles of (what is hopefully) dirt. Small passages lead off "
    "to the east and west, deeper into the morass of stench. A small tunnel "
    "leads off to the north and out of the burrow."
    );
  SetItems( ([
    ({ "pile", "piles", "dirt" }) : "These are piles that, looked at closely, appear to be waste.",
    ]) );
  SetInventory( ([
    TROG_NPC "trog2" : 2,
    ]) );
  SetSmell( ([
    "default" : "The burrow has a foul stench that seems to ooze from the walls.",
    "pile"    : "The piles of waste smell oddly like excrement.",
    ]) );
}