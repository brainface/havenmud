/*  Western Road
 *  Kresh Village
 */
#include <lib.h>
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("near a large and sturdy tent");
  SetLong(
    "A large and sturdy looking tent sits here, away from the heart of the "
    "village and yet obviously important. Footprints are beaten into the "
    "well-trodden grass here leading to and from the tent. Off to the "
    "west the grasses open to meet into a crossroads that connect the "
    "village to the Imperial Road."
    );
  SetItems( ([
      "tent" : "The tent is a large beast of a tent with crude "
               "symbols all over it.  A small sign is hanging from "
               "the entryway.",
      "sign" : "The sign has pictures of various types of weapons "
               "and armour.",
     ({ "symbol", "symbols" }) : "The symbols seem to display several "
                                 "types of weapons and armour.",
     ]) );
  SetEnters( ([
     "tent" : GOBLIN_TENT + "shop",
      ]) );
  SetRead("sign", "The sign has only pictures on it.");
  SetExits( ([
    "west" : GOBLIN_ROOM + "m_1",
    ]) );
  SetInventory( ([
    GOBLIN_NPC "spear_gob" : 2,
  ]) );
}
