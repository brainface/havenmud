// Templar invasion of Parva
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include "tip.h"

inherit LIB_INVASION;

#define startspot HAVENWOOD_TOWNS + "parva/room/path1"

static void create() {
  ::create();
  SetLeader(TIP_NPC + "captain");
  SetInvaders( ([
    TIP_NPC + "templar" : 10,
    TIP_NPC + "paladin" : 5,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "The Templars of Kylin are attacking Parva!",
    "leader_died" : "Capet Esterian has retreated from Parva!",
    "defeated"  : "The Templars of Kylin have retreated from Parva.",
  ]) );
  SetPlayerTitle("the Friend of Parva");
}
