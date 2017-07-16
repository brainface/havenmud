#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../path.h"
#include "/realms/torak/torak.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetRadiantLight(20);
  SetShort("%^RED%^by a pool of magma%^RESET%^");
  SetLong("lava pool here. hot. no touchy.");
  SetClimate("indoors");
  SetItems( ([
    ({ "lava", "pool" }) : "NO TOUCHY!",
    ]) );
  SetItemAdjectives( ([
    "lava" : ({ "hot", "lava" }),
  ]) );
  SetInventory( ([
  ]) );
  SetListen( ([
    "default" : "boiling magma",
  ]) );
  SetSmell( ([
    "default" : "sulphur",
  ]) );
  SetExits( ([
    "west" : ICE_ROOM "cave",
  ]) );
}
