// The second wave of the Demon Invasion of Soleil
// Originally invaded the WestWood
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include <daemons.h>
#include "dis.h"
inherit LIB_INVASION;

#define START WESTWOOD_TOWNS + "soleil/room/gate"

static void create() {   
  invasion::create();
  SetLeader(DIS_NPC + "maralith_leader");
  SetInvaders( ([
    DIS_NPC + "barbed2" : 5,
    DIS_NPC + "black_abashai2" : 7,
    DIS_NPC + "maralith2" : 6,
    DIS_NPC + "pf2" : 6,
  ]) );
  SetStartLocation(START);
  SetMessages( ([
    "announce" : "A second wave of demons has entered Soleil from the south!",
    "leader_died" : "The leader of the second wave has fallen!",
    "defeated" : "The second wave has been destroyed!",
  ]) );
}
