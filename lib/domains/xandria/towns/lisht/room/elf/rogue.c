#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "out" : LISHT_ROOM "elf/ra4",
    ]) );
  SetShort("inside the run down building");
  SetSmell("It smells like something has recently died in here.");
  SetListen("Frequent shuffling noises come from the refuse piles.");
  SetLong(
    "This building seems to be abandoned. Piles of refuse litter the "
    "floor, making movement through the building troubling at best "
    "and hazardous at worst. One of the piles appears to be flatter "
    "than the rest and, if possible, might even be a bed!"
    );
  SetItems( ([
    ({ "pile", "piles" }) : "The refuse piles are arranged arround the room "
                            "for maximum disgusting factor. One of the piles "
                            "appears to be a bed.",
       "bed" : "The bed pile is no less disgusting than the others.",
    ]) );
  SetInventory( ([
    LISHT_NPC "elf_rogue" : 1,
    ]) );   
}
