// Bandit Invasion of Parva

#include <lib.h>
#include <domains.h>
#include "bip.h"
inherit LIB_INVASION;

#define startspot HAVENWOOD_TOWNS + "parva/room/path1"

static void create() {
  ::create();
  SetLeader(BIP_NPC + "captain");
  SetInvaders( ([
    BIP_NPC + "bandit" : 10,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "Bandits are raiding Parva!",
    "leader_died" : "The bandit leader has been killed!",
    "defeated" : "The bandit raid on Parva has been crushed!",
  ]) );
  SetPlayerTitle("the Bandit Killer of Parva");
}
