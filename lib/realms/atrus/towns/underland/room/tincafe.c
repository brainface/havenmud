#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "out" : UNDER_ROOM "tin2",
    ]) );
  SetInventory( ([
    UNDER_NPC "sandy" : 1,
    ]) );
  SetShort("inside Sandy's Succulent Sweets");
  SetLong(
    "Sandy's place damnit."
    );
  SetItems( ([
    ({ "shelf", "shelves" }) : "The shelves are lined with wares.",
    ({ "ware", "wares" }) : "The various wares for sale can be browsed with the "
                            "help of the shopkeep.",
    ({ "desk" }) : "The desk is a small oak affair covered with papers.",
    ({ "paper", "papers" }) : "The papers seem to be various accounting documents.",
    ]) );
  SetSmell( ([
    "default" : "The scents of the wares argue amongst themselves here.",
    "ware"    : "The wares smell damp and musty.",
    ]) );
}
