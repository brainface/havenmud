//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside of a weaver's workshop");
  SetClimate("arid");
  SetLong(
    "The waters of Lake Rantera lap peaceably against the muddy "
    "banks here, which are dark with fertile silt. A building "
    "stands here, and the sign over the door shows a picture of a "
    "bolt of cloth and a needle. There are animal tracks here, and "
    "the building continues to the southeast while the lake spreads "
    "as far as the eye can see on the western horizon."
  );
  SetItems( ([
    ({ "building", "workshop" }) :
    "It is a long building, although not tall, built from "
    "bricks of mud. One could enter it.",
    ({ "lake", "water", "waters" }) :
    "Great Lake Rantera, from whence the River Itro flows.",
    ({ "sign" }) : 
    "The sign shows a needle and some cloth.",
    ({ "bank", "banks", "silt", "mud", "ground" }) : 
    "The muddy banks are thickly layered with black fertile silt.",
    ({ "track", "tracks" }) : 
    "The tracks seem to be from hooves of several sizes.",
  ]) );
  SetItemAdjectives( ([
  "banks" : ({ "muddy" }),
  "silt" : ({ "fertile", "dark" }),
  "building" : ({ "large", "mud-brick", "brick" }),
  "tracks" : ({ "animal" }),
  "workshop" : ({ "weavers", "weaver's" }),
  ]) );
  SetInventory( ([
    LAKE_NPC "sheep" : 2,
    LAKE_NPC "bull" : 1,
  ]) );
  SetListen("One can hear the sheep softly bahing.");
  SetSmell("It smells slightly of manure here.");
  SetExits( ([
    "west"  : LAKE_ROOM "/1f",
    "south"  : LAKE_ROOM "/2g",
  ]) );
  SetEnters( ([
    ({ "building", "workshop" }) : LAKE_ROOM "/1h",
  ]) );
}
