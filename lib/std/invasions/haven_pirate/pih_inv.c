// Pirate Invasion of Haven
// Original coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include "pih.h"
inherit LIB_INVASION;

#define startspot SOUTHERN_COAST_TOWNS + "haven/room/wharf"

static void create() {   
  invasion::create();
  SetLeader(PIH_NPC + "leader");
  SetInvaders( ([
    PIH_NPC + "pirate1" : 15,
    PIH_NPC + "pirate2" : 10,
    PIH_NPC + "pirate3" : 3,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "A ship of pirates has come to sack Haven Town!",
    "leader_died" : "The pirate's captain has fallen!",
    "defeated" : "The pirate first mate has sounded the retreat and "
    "the remainder of the pirates scurry aboard their ship as it pulls "
    "out to sea.",
  ]) );
  SetPlayerTitle("the Pirate Scourge");
}
