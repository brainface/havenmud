#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a comfortable office in Parva");
  SetExits( ([
    "east" : PARVA_ROOM "town_hall",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    PARVA_NPC "banker" : 1,
    ]) );
  SetLong(
    "This is the modest treasury of Parva, a small room partially walled off "
    "by a slapdash wooden partition, behind which stand the safely concealed "
    "moneys of Parvan citizens. A splintering opening in the partition allows "
    "for swift transactions to and from the treasury."
  );
  SetItems( ([
    "partition" : "The partition is wooden and seperates the room nicely.",
    "opening"   : "The opening appears to be protected to prevent all but "
                  "the Treasurer from entering.",
    ]) );
  SetItemAdjectives( ([
    "partition" : ({ "slapdash", "wooden" }),
    "opening"   : ({ "splintering" }),
    ]) );
  SetSmell("The Treasury smells of freshly oiled coins."); 
}