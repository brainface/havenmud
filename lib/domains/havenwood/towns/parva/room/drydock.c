#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a cavernous drydock by the wharf");
  SetExits( ([
    "out" : PARVA_ROOM "wharf4",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    PARVA_NPC "shipseller" : 1,
    PARVA_NPC "sailor_leader" : 1,
    ]) );
  SetLong(
    "A drydock is a large building, resembling a warehouse, where ships are "
    "assembled prior to their launch. A deep gouge in the floor allows the ship "
    "to be assembled and, once complete, the gouge is flooded and the ship floats "
    "out to sea. Once the ship leaves, the gouge is pumped dry and prepared for "
    "the next ship. A massive wooden door sits along the north side of the building "
    "to allow the water to be controlled."
    );
  SetItems( ([
    "gouge" : "The deep gouge is approximately 35 feet deep.",
    "door"  : "The door is large enough for a built ship to sail through.",
    ]) );
  SetSmell("An odor of mildew haunts the dock.");
}