//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in the office of the craftmaster");
  SetClimate("indoors");
  SetLong(
    "This small room seems roughly clear of clutter, except for "
    "a desk piled high with opened scrolls and trinkets. Here "
    "on the wall stands a large, brilliant tapestry depicting "
    "some person or another. A doorway leads east into a workshop "
    "and another goes south into a slightly quieter room. "
  );
  SetItems( ([
    ({ "desk" }) :
    "The desk is made of painstakingly carved pieces of wood.",
    ({ "scroll", "scrolls" }) :
    "The scrolls all deal with recipes for dyes and ceramics, or "
    "projections for next year's rise in papyrus prices.",
    ({ "trinket", "trinkets" }) : 
    "Jewelry, half-finished bits of pottery, scraps of fabric.",
    ({ "tapestry" }) : 
    "The tapestry appears to be a representation of the master "
    "craftsman, only he appears much better looking than he does "
    "in person.",
    "wall" : "There is a tapestry on one wall of this office.",
    "doorway" : "The doorways, which lead south and east, are "
    "made of scraps of old, inferior wood.",
  ]) );
  SetItemAdjectives( ([
  "scrolls" : ({ "opened" }),
  "tapestry" : ({ "large", "brilliant" }),
  ]) );
  SetInventory( ([
    LAKE_NPC "reddjedet" : 1,
  ]) );
  SetListen("Constant clattering comes from the west.");
  SetSmell("It smells like paper here.");
  SetExits( ([
    "south"  : LAKE_ROOM "/3a",
    "east" : LAKE_ROOM "/2b",
  ]) );
}
