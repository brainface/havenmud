/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "out" : "road06",
    ]) );
  SetInventory( ([
    UNDER_NPC "shopkeep" : 1,
    UNDER_NPC "merchant_leader" : 1,
    ]) );
  SetShort("inside a General Store");
  SetLong(
    "This General Store is the center of commerce here in the Underland. "
    "Various wares line the shelves, all respectably at gnome-height. "
    "A small desk sits towards the back of the shop with some papers "
    "strewn all over the top."
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