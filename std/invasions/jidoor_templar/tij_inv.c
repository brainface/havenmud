/*  Templar Invasion Code
 *  Edited: Laoise, 2005
 */

#include <lib.h>
#include <domains.h>
#include "tij.h"

#define startspot VALLEY_VIRTUAL + "valley/0,45"

inherit LIB_INVASION;

static void create() {
  ::create();
  SetLeader(TIJ_NPC + "captain");
  SetInvaders( ([
    TIJ_NPC + "templar" : 30,
    TIJ_NPC + "paladin" : 16,
  ]) );
  SetStartLocation(startspot);
  SetMessages( ([
    "announce"    : "The Templars of Kylin are attacking Jidoor!",
    "leader_died" : "The Grand Inquisitor has fled Jidoor!",
    "defeated"    : "The Templars of Kylin have retreated from Jidoor.",
  ]) );
  SetPlayerTitle("the Defender of Jidoor");
}
