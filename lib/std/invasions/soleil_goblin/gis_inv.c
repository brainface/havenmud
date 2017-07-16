// Goblin invasion of Soleil
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include "gis.h"

inherit LIB_INVASION;

#define startspot WESTWOOD_TOWNS + "soleil/room/gate"

static void create() {   
  invasion::create();
  SetLeader(GIS_NPC + "orc_leader");
  SetInvaders( ([
    GIS_NPC + "goblin_mercenary" : 5,
    GIS_NPC + "goblin_soldier2" : 15,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "An invasion force of goblins approaches Soleil!",
    "leader_died" : "The leader of the invasion has been killed!",
    "defeated" : "Soleil is once again safe!",
  ]) );
  SetPlayerTitle("the Defender of Soleil");
}
