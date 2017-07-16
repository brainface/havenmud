/* Wall road */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("the Foundation of a Fallen Tower");
  SetClimate("indoors");

  SetNightLight(30);

  SetLong("While the foundation of the tower still stands proudly, the "
    "upper stories have completely collapsed. The floor is a jumble of "
    "rotten timbers and rusted metal bits, and in the center, a long steel "
    "rod is twisted and broken. The tower's upper stories lie fallen to the "
    "east, cavernlike.");

  SetItems( ([

  ]) );

  SetExits( ([
    "east" : ROOM "/mage_tower1",
    "out" : ROOM "/upperE",
  ]) );

  SetSmell( ([
    "default"  : "It smells of mold and rotten meat.",
  ]) );

  SetListen( ([
    "default"  : "Chittering and chirping insects chatter somewhere "
      "just out of sight.",
  ]) );

  SetInventory( ([
    //NPC "/koboldm"  : 2
  ]) );

}

