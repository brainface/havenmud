//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("on the banks of Lake Rantera");
  SetClimate("arid");
  SetLong(
    "The waters of Lake Rantera lap peaceably against the muddy "
    "banks, which are dark with fertile silt. A building stands "
    "to the north, and the lake itself governs the western "
    "horizon. Several animal tracks are in the mud here, and many "
    "plants shoot emeraldine from the ground."
  );
  SetItems( ([
    ({ "building" }) :
    "It is a long building, although not tall, built from "
    "bricks of mud.",
    ({ "lake", "water", "waters" }) :
    "Great Lake Rantera, from whence the River Itro flows.",
    ({ "plants" }) : 
    "Cattails, sedge, papyrus, and beautiful lilies.",
    ({ "bank", "banks", "silt", "mud", "ground" }) : 
    "The muddy banks are thickly layered with black fertile silt.",
    ({ "track", "tracks" }) : 
    "The tracks seem to be from large birds.",
  ]) );
  SetItemAdjectives( ([
  "banks" : ({ "muddy" }),
  "silt" : ({ "fertile", "dark" }),
  "building" : ({ "large", "mud-brick", "brick" }),
  "tracks" : ({ "animal" }),
  ]) );
  SetInventory( ([
    LAKE_NPC "ostrich" : 1,
  ]) );
  SetListen("The sounds of the water are clearly heard.");
  SetSmell("The scent of fresh water flows through the air.");
  SetExits( ([
    "west"  : LAKE_ROOM "/4g",
    "north"  : LAKE_ROOM "/3h",
    "south"  : LAKE_ROOM "/5h",
  ]) );
}
