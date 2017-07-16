//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_FISHING;

int MakeCaptain();
static void create() {
  fishing::create();
  SetShort("a dock on western Lake Rantera");
  SetClimate("arid");
  SetProperty("coastal",1);
  SetLong(
    "Here stands a dock on the banks of Lake Rantera, merely a "
    "few wooden planks jutting out into the water. One stake "
    "is here for the ferryman to tie his skiff to. The waters "
    "slap playfully against the dock. A building lies just to "
    "the west, and it appears to be some sort of workshop. "
  );
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
    "The building is off to the west. ",
  ]) );
  SetItemAdjectives( ([
  "planks" : ({ "wooden" }),
  "waters" : ({ "playful" }),
  ]) );
  SetListen("Waves gently slap the dock.");
  SetSmell("The air smells fresh and slightly like the lake.");
  SetExits( ([
    "east" : LAKE_ROOM "/3d",
    "south" : LAKE_ROOM "/4c",
    "north" : LAKE_ROOM "/2c",
    "west" : LAKE_ROOM "/3b",
  ]) );
  SetInventory( ([
    LAKE_NPC "ibis" : 2,
    LAKE_NPC "nekhonkh" : 1,
    LAKE_OBJ "ferry" : 1,
  ]) );
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
      DIR_STD "fish/boot" : 1,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
}

int MakeCaptain() {
  object captain = new(LAKE_NPC "nekhonkh");
  object ferry = present("ferry", this_object());
  if (!captain) return 0;
  if (!ferry) return 0;
  captain->eventMove(ferry);
  return 1;
}
