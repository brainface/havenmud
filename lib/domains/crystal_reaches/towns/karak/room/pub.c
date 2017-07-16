// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(45);
  SetShort("the Buggered Muezzin pub");
  SetLong(
    "The Karak pub is a rowdy, noisy building built to serve food "
    "and drink to the citizens of the town. On the far side of the "
    "room is a bar with several stools, some standing, some not. "
    "There are several tables scattered about with no apparent pattern. "
    "The rendered hide of a muezzin is displayed on hooks sticking out "
    "of the wall behind and above the bar."
  );
  SetItems( ([
    ({ "pub", "room", "muezzin" }) : (: GetLong :),
    ({ "bar" }) : "The bar occupies most of the far wall, with space "
    "on either side for servers to walk around it. It is made of the "
    "same plain wood as the rest of the room.",
    ({ "stool", "stools" }) : "Sturdy wooden stools are clustered near "
    "the bar, some upright, others lying on their sides. A few seem "
    "scarred, as if a corrosive liquid were poured on them.",
    ({ "table", "tables" }) : "The tables are made of the same wood "
    "as everything else in the room and seem well-built enough to stand "
    "up to years of abuse. Their tables are scarred and stained with "
    "previous use.",
  ]) );
  SetItemAdjectives( ([
    "pub"  : ({ "karak", "the", "buggered", "rowdy", "noisy" }),
    "bar" : ({ "plain", "wood", "wooden", }),
    "stool" : ({ "sturdy", "wooden", "clustered", "upright", 
    "lying", "scarred", "corroded" }),
    "table" : ({ "wood", "well", "built", "scarred", "stained" }),
  ]) );
  SetSmell( ([
    "default" : "The place smells of grog, vomit, and sweat.",
  ]) );
  SetListen( ([
    "default" : "A lingering echo of violent threats and drunken "
    "remains in the air.",
  ]) );
  SetNewsgroups( ({ "player.general" }) );
  SetInventory( ([
    KARAK_NPC + "barkeep" : 1,
    KARAK_NPC + "healer" : 1,
  ]) );
  SetExits( ([
    "out" : KARAK_ROOM + "rd6",
  ]) );
}
