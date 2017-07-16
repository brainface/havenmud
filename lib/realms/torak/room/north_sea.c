#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../torak.h"
#include "../ice_isle/path.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("ocean", 1);
  SetClimate("arctic");
  SetShort("a vast sea");
  SetDayLong("The sun glistens across the broken "
    "surface of the vast sea. The water glimmers deep "
    "blue reflecting the sky. Waves lap back and "
    "forth, up and down.");
  SetNightLong("A thin mist glows over the water, "
    "barely lit from the nightime moonshine. The "
    "water is dark and deep black. Waves lap back "
    "and forth, up and down.");
  SetListen( ([
    "default" : "The sea is quiet.",
  ]) );
  SetSmell( ([
    "default" : "The air is crisp and clean, with only a slightly salty smell.",
  ]) );
  SetExits( ([
    "north" : ICE_ROOM "port",
    "east" : TORAK "dalnairn/room/-3,0",
    "south" : TORAK "workroom",
  ]) );
  SetInventory( ([
  ]) );
}
