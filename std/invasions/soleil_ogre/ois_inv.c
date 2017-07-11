// Ogre invasion of Soleil
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include "ois.h"
inherit LIB_INVASION;


#define startspot WESTWOOD_TOWNS + "soleil/room/gate"

static void create() {   
  invasion::create();
  SetLeader(OIS_NPC + "leader");
  SetInvaders( ([
    OIS_NPC + "ogre1" : 17,
    OIS_NPC + "ogre2" : 17,
    OIS_NPC + "ogre3" : 5,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "Ogres have come to attack Soleil!",
    "leader_died" : "The shaman has been killed!",
    "defeated" : "Soleil has beaten back the invasion!"
  ]) );
  SetPlayerTitle("the Defender of the Joyful");
}
