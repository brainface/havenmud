#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the ruins of a tavern");
  SetLong(
    "The ruined tavern has seen better days. There is no furniture, but the "
    "hearth still stands, and appears to have been used recently.  Lying near "
    "the hearth is a small sleeping mat and some personal effects as if the "
    "ruins have become home to someone."
    );
  SetItems( ([
    "hearth" : "The hearth, or firepit, appears to have been recently used.",
    "mat"    : "This small sleeping mat appears smaller than human sized.",
    ]) );
  SetSmell( ([
    "default" : "The hearth smells to have been recently used.",
    "hearth"  : "The hearth smells of burnt wood.",
    ]) );
  SetItemAdjectives( ([
    "mat" : ({ "small", "sleeping" }),
    ]) );
  SetInventory( ([
    NPC "/rat_vendor" : 1,
    ]) );
  SetExits( ([
    "out" : ROOM "/ruins7",
    ]) );
}
  