// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"

inherit LIB_ROOM;
static void create() {
  room::create();
  SetShort("the marketplace of Karak");
  SetLong(
    "Three wooden buildings stand here, their adjoining walls touching "
    "and their roof shared. All three buildings have nearly identical "
    "entrances, distinguished only by the signs above them. The northernmost "
    "building bears a sign depicting a variety of goods. The middle building "
    "displays a vest of chainmail, while the southernmost building has above "
    "its entrance the representation of crossed axes. A dirt path leads west, back "
    "to the crossroads of Karak."
  );
  SetItems( ([
    ({ "buildings" }) : "Three buildings stand here, joined together by their "
    "shared roof. Each has a unique sign above its entrance, but otherwise "
    "they are identical.",
    ({ "north building", "northern building", "northernmost building", 
    "store" }) : "The northern building bears a sign showing a variety of "
    "goods, suggesting it might be a general store.",
    ({ "middle building", "armoury" }) : "The middle building displays a sign "
    "with a vest of chainmail on it, suggesting it may be the local armoury.",
    ({ "south building", "southern building", "southernmost building", 
    "smithy" }) : "The most southern of this row of buildings has a sign with "
    "crossed swords on it, indicating it may be the local smithy.",
    ({ "path", "dirt" }) : "This dirt path is a branch from the main road "
    "through Karak, which lies to the west of here.",
  ]) );
  SetItemAdjectives( ([
    "buildings" : ({ "wooden", "joined", "three", "adjoining", "identical" }),
    "store" : ({ "general" }),
    "path" : ({ "dirt" }),
  ]) );
  SetListen( ([
    "default" : "Clanging noises come from both the armoury and the smithy",
  ]) );
  SetSmell( ([
    "default" : "The smell of smoke is strong here.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "soldier" : 2,
  ]) );
  SetExits( ([
    "west" : KARAK_ROOM + "rd3",
  ]) );
  SetEnters( ([ 
    "armoury" : KARAK_ROOM + "shop_armoury",
    "smithy"  : KARAK_ROOM + "shop_smithy",
    "store"   : KARAK_ROOM + "shop_general",
  ]) );
}
