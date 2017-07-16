// Pirate invasion of Parva
// Original coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include "pip.h"
inherit LIB_INVASION;

#define startspot HAVENWOOD_TOWNS + "parva/room/docks1"

static void create() {   
  invasion::create();
  SetLeader(PIP_NPC + "/parva_leader");
  SetInvaders(([
    PIP_NPC + "parva_pirate1" : 18,
    PIP_NPC + "parva_pirate2" : 20,
    PIP_NPC + "parva_pirate2" : 5,
  ]));
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "A ship of pirates has come to sack Parva!",
    "leader_died" : "The pirate's captain has fallen! "
      "The defenders of Parva are gaining their "
      "victory against the pirates!",
    "defeated" : "The first mate of the pirates sacking "
      "Parva sounds the retreat and all the pirates "
      "still alive in the town run back to the "
      "ship for hasty retreat. Parva's defenders "
      "are victorious!"
  ]) );
  SetPlayerTitle("the Defender of Parva against Pirates");
}
