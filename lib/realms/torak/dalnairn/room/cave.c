//
// Dalnairn Total Recode
// Torak@Haven
// 2014-2017
//

#include <lib.h>
#include <domains.h>
#include <dirs.h>
#include "../dalnairn.h"

inherit LIB_FISHING;

static void create() {
  ::create();
  if(query_night()) {
    SetProperty("coastal", 1);
    SetShort("inside a rocky cave");
    SetSpeed(5);
    SetFish(( [ 
    ]));
    SetChance(25);
    SetMaxFishing(25);
    SetItems( ([
      ({ "cave", "wall", "walls", "moonlight" }) :
         (: GetLong :), 
      ({ "pool", "pools", "floor" }) :
         "Shallow pools of water lay scattered about the cave floor",
    ]) );
    SetItemAdjectives( ([
      "pool" : ({ "shallow" }),
      "cave" : ({ "rocky" }),
    ]) );
    SetListen( ([
      "default" : "Muted sounds of breaking waves echo inside the dripping cave.",
    ]) );
    SetSmell( ([
      "default" : "The air is damp and salty.",
    ]) );

  } else {

    SetProperty("shallows", 1);
    SetShort("submerged in an underwater cave");
    SetSpeed(5);
    SetFish(( [ 
    ]));
    SetChance(25);
    SetMaxFishing(25);
    SetItems( ([
      ({ "cave", "wall", "walls" }) :
         (: GetLong :), 
    ]) );
    SetItemAdjectives( ([
      "cave" : ({ "rocky" }),
    ]) );
  }
  SetClimate("underground");
  SetDayLong(
    "This rocky cave is below sea level. "
    "The rocky walls are jagged and submerged. ",
  );
  SetNightLong(
    "This rocky cave is below sea level. "
    "Shallow pools of water lay scattered about the ground. "
    "The rocky walls are jagged and soaked in moonlight. ",
  );
  SetInventory( ([
    DAL_OBJ "oyster" : 9 + random(10) + random(10),
  ]) );
  SetExits( ([
    "out" : DAL_ROOM "-1,-3.c",
  ]) ); 
}
