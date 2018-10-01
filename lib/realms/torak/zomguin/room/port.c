#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../path.h"
#include "/realms/torak/torak.h"

inherit LIB_FISHING;

static void create() {
  ::create();
  SetProperty("coastal", 1);
  SetNoClean(1);
  SetSpeed(5);
  SetFish(( [
  ]) );
  SetChance(25);
  SetMaxFishing(25);
  SetShort("portspot");
  SetLong("hey a parking place.  finally.");
  SetClimate("arctic");
  SetItems( ([
    ({ "place", "parking" }) : (: GetLong :),
    ]) );
  SetItemAdjectives( ([
    "place" : ({ "parking" }),
  ]) );
  SetInventory( ([
    ZOMGUIN_NPC "penguin" : random(2) + 1,
    ZOMGUIN_NPC "penguin_steal" : random(2) + 1,
    ZOMGUIN_NPC "penguin_aggro" : random(1),
  ]) );
  SetListen( ([
    "default" : "penguins",
  ]) );
  SetSmell( ([
    "default" : "penguins",
  ]) );
  SetExits( ([
    "north" : ZOMGUIN_ROOM "rocks",
    "south" : TORAK_ROOM "north_sea",
  ]) );
}
