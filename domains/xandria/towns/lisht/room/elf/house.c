#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(30);
  SetShort("inside a decrepid hovel");
  SetLong(
    "This hovel is a small, cramped home for a small family. "
    "Blankets sit next to what appears to be a small straw sleeping "
    "pallet. A rough wooden table serves as the central focus of "
    "the hovel. The hovel is dimly lit and is a fairly unpleasant "
    "acknowledgment of living conditions for the slaves of Lisht."
    );
  SetItems( ([
    ({ "blanket", "blankets" }) : "The blankets are roughspun and "
                                  "do not appear to offer much "
                                  "protection from the cold.",
    ({ "pallet" }) : "The sleeping pallet is a thin wooden base "
                     "with straw sitting upon it.",
    "table" : "The table is rough wood, but serves its purpose admirably.",
    ]) );
  SetItemAdjectives( ([
    "pallet" : ({ "straw", "sleeping" }),
    "table"  : ({ "rough", "wooden" }),
    ]) );                                                       
  SetSmell( ([
    "default" : "A faintly moldy smell comes from the pallet.",
    "pallet"  : "The pallet's straw smells of mold.",
    ]) );
  SetInventory( ([
    LISHT_NPC "mother" : 1,
    LISHT_NPC "sister" : 1,
    LISHT_NPC "moses"  : 1,
    LISHT_NPC "aaron"  : 1,
    ]) );
  SetExits( ([
    "out" : LISHT_ROOM "elf/ra1",
    ]) );
}
