/*   The main hall of the Dark order guild hall
     Portia  5-11-99
 */

#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small foyer");
  SetClimate("indoors");
  SetExits( ([
    "out" : "/domains/havenwood/areas/wood/rooms/river",
    "west" : "/domains/havenwood/areas/darkorderguild/common",
    ]) );
  SetListen( ([
    "default" : "The room is mysteriously silent.",
    ]) );
  SetSmell( ([
    "default" : "The shack smells of stale ale.",
    ]) );
  SetInventory( ([
    ]) );
  SetLong("The inside of this small shack leaves much to be desired."
    " The walls are bare and there is no furnishing of any kind. "
    "The floor is littered with leaves and dirt, and the ceiling "
    "has many holes that allow beams of light to enter. There "
    "is what looks to be a common room off to the west.");
  SetItems( ([
    ({"room", "shack", "foyer"}) : (:GetLong:),
    ({"walls", "wall"})  : "The walls are completely bare.",
    ({"ceiling", "holes", "hole"}) : "Holes in the ceiling allow "
      "beams of light to filter into the room.",
    ({"light", "beams"}) : "Beams of light filter into the room.",
    ({"leaves", "leaf", "dirt", "floor"}) : "Leaves and dirt litter "
      "the floor.",
    ]) );
  SetItemAdjectives( ([
    "room" : ({"small"}),
    "walls" : "bare",
    "light" : "beams of",
    ]) );
    }

