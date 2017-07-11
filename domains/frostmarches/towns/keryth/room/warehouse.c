#include <lib.h>
#include "../keryth.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : K_ROOM "/wharf",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("inside the Outfitter's Drydock");
  SetLong(
    "This inside of the cavernous warehouse is a sight to behold. "
    "All around the floor of the warehouse are piles of lumber, and "
    "suspended from the ceiling are literally dozens of small ships' keels "
    "in various states of construction. At the far side of the warehouse "
    "there is an artificial inlet of water allowing the completed keels to "
    "be launched easily."
    );
  SetSmell("The warehouse smells of dust and freshly cut lumber.");
  SetListen("Workmen build ships around the clock.");
  SetItems( ([
    ({ "pile", "piles", "lumber" }) : "The lumber is stacked neatly and "
                                      "arranged by size and function.",
    ({ "ship", "ships", "keel", "keels" }) : "The ships' keels are incomplete "
                                      "skeletons of what will some day be ships.",
    ]) );
  SetInventory( ([
    K_NPC "/shipseller" : 1,
    K_NPC "/shiptrainer": 1,
    K_NPC "/viking" : 1,
    ]) );
}