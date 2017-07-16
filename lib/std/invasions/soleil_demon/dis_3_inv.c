// The third wave of the Demon Invasion of Soleil
// Originally invaded the WestWood
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include <daemons.h>
#include "dis.h"
inherit LIB_INVASION;

#define START WESTWOOD_TOWNS + "soleil/room/tree_c"

static void create() {   
  invasion::create();
  SetLeader(DIS_NPC + "pf_leader");
  SetInvaders( ([
    DIS_NPC + "bane3" : 5,
    DIS_NPC + "maralith3" : 6,
    DIS_NPC + "pf3" : 6,
  ]) );
  SetStartLocation(START);
  SetMessages( ([
    "announce" : "A third wave of demons claws through a rift before Soleil's "
    "northern gates!",
    "leader_died" : "The leader of the demon army has fallen!",
    "defeated" : "The demon army has been routed and lies in ruins!",
  ]) );
  SetPlayerTitle("the Closer of the WestWood Rift");
}
