/*  A real invasion!
 *
 * Duuk 10-03-97
 * Edited: Laoise, 2005
 * Edited: Urien, 2013
 */
#include <lib.h>
#include "domains.h"
#include "uih.h"
inherit LIB_INVASION;

#define startspot SOUTHERN_COAST_TOWNS "/haven/room/imperial_road/ir2"

static void create() {
  invasion::create();
  SetLeader(UIH_NPC + "vampire2");
  SetInvaders( ([
    UIH_NPC + "skel_sshrine" : 5,
    UIH_NPC + "skel_bathhouse" : 2,
    UIH_NPC + "skel_hosp" : 5,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce"    : "The second echelon of undead arrives!",
    "leader_died" : "The Vampire Lieutenant of the Second Echelon has been destroyed!",
    "defeated"    : "The second echelon is vanquished!",
  ]) );
}
