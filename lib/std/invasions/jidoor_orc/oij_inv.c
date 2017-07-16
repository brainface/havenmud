//
// Orc invasion for Jidoor
// Created by Zaxan@Haven
// Invasion Header file added by Dylanthalus@Haven
// Edited: Laoise, 2005

#include <lib.h>
#include <domains.h>
#include "oij.h"
inherit LIB_INVASION;

#define startspot VALLEY_TOWNS + "jidoor/room/maingate"

static void create() {
   invasion::create();
   SetLeader(
     OIJ_NPC + "orc1"
   );
   SetInvaders( ([ 
     OIJ_NPC + "orc1" : 8,
     OIJ_NPC + "orc2" : 5,
     OIJ_NPC + "orc3" : 3,
   ]) );
   SetStartLocation(startspot);
   SetMessages( ([ 
     "announce" : "Orcs are invading Jidoor!",
     "leader_died" : "The leader of the first Orc wave has been slain!",
     "defeated" : "The first group of Orcs has been defeated!"
  ]) );
}
