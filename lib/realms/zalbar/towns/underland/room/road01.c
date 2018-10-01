/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  ::create();
  SetShort("along a road in the Underland");
  SetExits( ([
    "east" : UNDER_ROOM "road02",
    ]) );
  AddExit("west", UNDER_ROOM "gate", (: PreExit :) );
  SetSmell("The smells of gnomish cooking come from the tavern.");
  SetListen("Loud conversation comes from the tavern.");
  SetLong(
    "The road continues to the east and west from here. To the south "
    "sits a large stone building which serves as a tavern. Further to the east "
    "Mount Trog can be seen, from which the gnomish city takes its name, \"the "
    "Land Under the Mountain\", or \"Underland\" for short."
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "tavern", "building" }) : "The tavern sits merrily to the south.",
    ]) );
  SetEnters( ([
    "tavern" : UNDER_ROOM "tavern",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : 2,
    ]) );
}

int PreExit() {
  if (!userp(this_player())) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
