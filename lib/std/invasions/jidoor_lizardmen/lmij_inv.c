/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: limj_inv.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: December 20th, 1998
// Abstract: Invasion Object for Lizardmen Raid on Jidoor
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "lmij.h"
inherit LIB_INVASION;

static void create() {
  invasion::create();
  SetLeader(
    LMIJ_NPC + "/lead_lizardman"
  );
  SetInvaders( ([ 
    LMIJ_NPC + "/lizardman1" : 10,
    LMIJ_NPC + "/lizardman2" : 6,
    LMIJ_NPC + "/lizardman3" : 6,
  ]) );
  SetStartLocation("/domains/valley/towns/jidoor/room/maingate");
  SetMessages( ([ 
    "announce" : "A band of Lizardmen are raiding Jidoor!",
    "leader_died" : "The leader of the lizardmen has been slain!",
    "defeated" : "The Lizardmen raid on Jidoor has been beaten back!"
  ]) );
  SetPlayerTitle("the Protector of Jidoor");
}
