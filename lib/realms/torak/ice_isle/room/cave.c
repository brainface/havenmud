#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../path.h"
#include "/realms/torak/torak.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inse a cave");
  SetLong("cold, dark cave.");
  SetClimate("indoors");
  SetItems( ([
    ({ "cave" }) : (: GetLong :),
    ]) );
  SetItemAdjectives( ([
    "cave" : ({ "cold", "dark" }),
  ]) );
  SetInventory( ([
  ]) );
  SetListen( ([
    "default" : "wind rips past through the opening",
  ]) );
  SetSmell( ([
    "default" : "sulphur",
  ]) );
  SetExits( ([
    "east" : ICE_ROOM "pool",
    "out" : ICE_ROOM "hill",
  ]) );
}
