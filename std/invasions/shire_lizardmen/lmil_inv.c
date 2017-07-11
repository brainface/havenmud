// Lizardman invasion of Lloryk
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include "lmil.h"
inherit LIB_INVASION;

#define startspot CRYSTAL_REACHES_AREAS + "gwonish/room/path1"

static void create() {
  ::create();
  SetLeader(LMIL_NPC + "leader");
  SetInvaders( ([
    LMIL_NPC + "raider" : 12,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce"    : "Lizardmen from the Gwonish Swamp are raiding the Shire!",
    "leader_died" : "The lizardman chief has fallen!",
    "defeated"    : "The lizardman raiding party is crushed!",
  ]) );
  SetPlayerTitle("the Hero of the Shire");
}
