/*  A real invasion!
 *
 * Duuk 10-03-97
 * Edited: Laoise, 2005
 * Edited: Urien, 2013
 */

#include <lib.h>
#include <domains.h>
#include "uih.h"
inherit LIB_INVASION;

#define startspot SOUTHERN_COAST_TOWNS "/haven/room/imperial_road/ir2"

static void create() {
  invasion::create();
  SetLeader(UIH_NPC + "lich");
  SetInvaders( ([
    UIH_NPC + "skel_guard" : 4,
    UIH_NPC + "skel_pons" : 8,
    UIH_NPC + "skel_inn" : 6,
    UIH_NPC + "vampire1" : 1,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce"    : "A horde of undead creatures are raising against Haven!",
    "leader_died" : "The Lich King has been destroyed!",
    "defeated"    : "The undead horde is vanquished!",
  ]) );
  SetPlayerTitle("the Destroyer of the Undead Host");
}
