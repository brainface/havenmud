#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west" : LISHT_ROOM "gnoll/pr3",
    "east" : LISHT_ROOM "gnoll/pr1",
    "north": LISHT_ROOM "gnoll/bazaar",
    ]) );
  SetShort("along the Pharaoh's Road");
  SetLong(
    "The road continues to the west and east from here. To the west lies the palace "
    "of the Pharaoh, a massive building of cut stone block. To the north lies the "
    "Lisht Bazaar, a meeting place for buyers and sellers of all variety. To the east "
    "is the Wall of Lisht which seperates the citizens from the slaves."
    );
  SetInventory( ([
    LISHT_NPC "child" : 2,
  ]) );
  SetListen("Sounds of business come from the north at all hours.");
}
