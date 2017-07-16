/* Bandit invasion of Sanctum
 * Duuk 10-03-97
 * Edited: Laoise, 2005
 */

#include <lib.h>
#include <domains.h>
#include "bis.h"
inherit LIB_INVASION;

#define startspot PENINSULA_VIRTUAL "vimp/0,0"

static void create() {
  invasion::create();
  SetLeader(BIS_NPC + "leader");
  SetInvaders( ([
     BIS_NPC + "bandit"  : 8,
     BIS_NPC + "bandit2" : 5,
     BIS_NPC + "bandit3" : 3,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce"    : "Bandits are Invading Sanctum!",
    "leader_died" : "The Bandit Leader has Fallen!",
    "defeated"    : "The Bandit Invasion has been beaten back!",
  ]) );
  SetPlayerTitle("the Bandit Killer");
}
