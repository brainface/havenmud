//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_FISHING;
//int MakeCaptain();

static void create() {
  fishing::create();
  SetShort("a dock on eastern Lake Rantera");
  SetClimate("arid");
  SetLong(
    "Here stands a dock on the banks of Lake Rantera, merely a "
    "few wooden planks jutting out into the water. One stake "
    "is here for the ferryman to tie his skiff to. The waters "
    "slap playfully against the dock. A building lies just to "
    "the east, and it appears to be some sort of workshop. "
  );
  SetProperty("coastal",1);
  SetItems( ([
    ({ "dock" }) : (: GetLong :),
    ({ "plank", "planks" }) :
    "The planks are old scraps of inferior timber. ",
    ({ "stake" }) :
    "The mooring stake is little more than a splinter of old "
    "wood one could lash a boat to.",
    ({ "waters", "water", "lake" }) :
    "Lake Rantera's waters are dark with the color of mud. ",
    ({ "building", "workshop" }) :
    "The building is off to the east. ",
  ]) );
  SetItemAdjectives( ([
  "planks" : ({ "wooden" }),
  "waters" : ({ "playful" }),
  ]) );
  SetListen("Waves gently slap the dock.");
  SetSmell("The air smells fresh and slightly like the lake.");
  SetExits( ([
    "east" : LAKE_ROOM "/3h",
    "south" : LAKE_ROOM "/4g",
    "north" : LAKE_ROOM "/2g",
    "west" : LAKE_ROOM "/3f",
  ]) );
  SetInventory( ([
    LAKE_NPC "ibis" : 2,
//    LAKE_NPC "nekhonkh" : 1,
//    LAKE_OBJ "ferry" : 1,
  ]) );
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
      DIR_STD "fish/boot" : 1,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
}

