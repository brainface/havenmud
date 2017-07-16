// Pirate Invasion of Haven
// Original coder: Unknown
// Edited: Urien 2013

#include <lib.h>
#include <domains.h>
#include "nit.h"

inherit LIB_INVASION;

#define startspot TAIRI_TOWNS + "tairi/room/path11"

static void create() {   
  invasion::create();
  SetLeader(NIT_NPC + "ninja1");
  SetInvaders( ([
    NIT_NPC + "ninja1" : 15,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "A wave of ninja have invaded Tairi!",
    "leader_died" : "The ninja leader has fallen!",
    "defeated" : "The ninja survivors flee with no honor!",
  ]) );
  SetPlayerTitle("the Ninja Exterminator");
}
