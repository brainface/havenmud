// The first wave of the Demon Invasion of Soleil
// Originally invaded the WestWood
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include <daemons.h>
#include "dis.h"
inherit LIB_INVASION;

#define START WESTWOOD_TOWNS "soleil/room/up1"

static void create() {   
  invasion::create();
  SetLeader(DIS_NPC + "bane_leader");
  SetInvaders( ([
    DIS_NPC + "barbed1" : 10,
    DIS_NPC + "black_abashai1" : 10,
    DIS_NPC + "lemure1" : 15,
  ]) );
  SetStartLocation(START);
  SetMessages( ([
    "announce" : "A rift has open in the WestWood and demons are "
    "descending upon Soleil!",
    "leader_died" : "The leader of the first wave has fallen!",
    "defeated" : "The first wave of demons has been destroyed!",
  ]) );
}