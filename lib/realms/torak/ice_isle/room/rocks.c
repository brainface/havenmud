#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../path.h"
#include "/realms/torak/torak.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("rocks and shit");
  SetLong("rocks.  ice.  shit.");
  SetClimate("arctic");
  SetItems( ([
    ({ "shit", "ice", "rocks" }) : (: GetLong :),
    ]) );
  SetItemAdjectives( ([
    "" : ({ "" }),
  ]) );
  SetInventory( ([
    ICE_OBJ "path_up" : 1,
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
    "south" : ICE_ROOM "port",
  ]) );
}
