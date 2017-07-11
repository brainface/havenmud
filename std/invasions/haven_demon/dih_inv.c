/* A Test Invasion 
 *
 * Duuk 10-03-97
 * Edited by Laoise, 2005
 */

#include <lib.h>
#include <domains.h>
#include "dih.h"
inherit LIB_INVASION;

#define startspot SOUTHERN_COAST_TOWNS + "haven/room/gate"

static void create() {
  invasion::create();
  SetLeader(DIH + "maralith");
  SetInvaders( ([
    DIH + "maralith" : 4,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce" : "A rift opens, spewing demons into Haven Town!",
    "leader_died" : "The chieftain of the Demons has been slain!",
    "defeated" : "The demon invasion has been vanquished!",
  ]) );
  SetPlayerTitle("the Demon Hunter");
}
