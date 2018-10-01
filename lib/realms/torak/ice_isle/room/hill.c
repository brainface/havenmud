#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../path.h"
#include "/realms/torak/torak.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("rocky hill");
  SetLong("rocky hill.  a cave.");
  SetClimate("arctic");
  SetItems( ([
    ({ "cave" }) : "look, a cave.",
    ({ "hill" }) : (: GetLong :),
    ]) );
  SetItemAdjectives( ([
    "hill" : ({ "rocky" }),
  ]) );
  SetInventory( ([
    ICE_OBJ "path_down" : 1,
    ICE_NPC "penguin" : random(2) + 1,
    ICE_NPC "penguin_steal" : random(2) + 1,
    ICE_NPC "penguin_aggro" : random(1),
  ]) );
  SetListen( ([
    "default" : "penguins",
  ]) );
  SetSmell( ([
    "default" : "penguins",
  ]) );
  SetExits( ([
  ]) );
  SetEnters( ([
    "cave" : ICE_ROOM "cave",
  ]) );
}
