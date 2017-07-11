/*   Portia   5-11-99
     The common room of the dark order guild hall.
 */

#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small meeting room");
  SetClimate("indoors");
  SetExits( ([
    "east" : "/domains/havenwood/areas/darkorderguild/main",
    ]) );
  SetListen( ([
    "default" : "The room is eerily quiet.",
    ]) );
  SetSmell( ([
    "default" : "The room smells of grass and dirt.",
    ]) );
  SetInventory( ([
    ]) );
  SetLong("This is apparently the common room of the guild hall. "
    "There are logs that serve as makeshift benches, and a large "
    "board sits at the front of the room. A single window allows "
    "light to filter into the room. The only way out of here is to "
    "the east; where the main foyer lies.");
  SetItems( ([
    ({"common room", "room", "hall"}) : (:GetLong:),
    ({"logs", "log", "benches", "bench"}) : "The logs serve as "
        "benches.",
    ({"window", "light"}) : "The light that filters in through the"
        " window is filled with dust particles.",
    ({"particles", "particle", "dust"}) : "The dust particles shimmer "
        "in the light.",
    ]) );
  SetItemAdjectives( ([
    "common room" : ({"common", "guild"}),
    "logs"  : "makeshift",
    "window" : "single",
    "particles" : "dust",
    ]) );
  }


