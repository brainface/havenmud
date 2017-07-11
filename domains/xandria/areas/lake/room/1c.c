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
    "off to the southwest, and the lake itself governs the eastern "
    "horizon. Several animal tracks are in the mud here, and many "
    "plants shoot emeraldine from the ground."
  );
  SetItems( ([
    ({ "building" }) :
    "It is a long building, although not tall, built from "
    "bricks of mud.",
    ({ "lake", "water", "waters" }) :
    "This is the Great Lake Rantera, into which the River Itro flows.",
    ({ "plants" }) : 
    "Cattails, sedge, papyrus, and beautiful lilies.",
    ({ "bank", "banks", "silt", "mud", "ground" }) : 
    "The muddy banks are thickly layered with black fertile silt.",
    ({ "track", "tracks" }) : 
    "The tracks seem to be from little birds.",
  ]) );
  SetItemAdjectives( ([
  "banks" : ({ "muddy" }),
  "silt" : ({ "fertile", "dark" }),
  "building" : ({ "large", "mud-brick", "brick", "long" }),
  "tracks" : ({ "animal" }),
  ]) );
  SetInventory( ([
    LAKE_NPC "ibis" : 3,
  ]) );
  SetListen("The sounds of the water are clearly heard.");
  SetSmell("The scent of fresh water flows through the air.");
  SetExits( ([
    "east"  : LAKE_ROOM "/1d",
    "west"  : LAKE_ROOM "/1b",
    "south"  : LAKE_ROOM "/2c",
  ]) );
}
