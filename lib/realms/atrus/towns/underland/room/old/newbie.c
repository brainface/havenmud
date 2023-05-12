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
  SetShort("inside the Meeting Hall");
  SetExits( ([
    "out" : UNDER_ROOM "road04",
    ]) );
  SetInventory( ([
    UNDER_NPC "equipper" : 1,
    UNDER_NPC "quest"    : 1,
    ]) );
  SetLong(
    "The inside of this meeting hall is a friendly and relaxed place. "
    "Scattered around the hall are various chairs, all perfectly gnome-sized, "
    "all comfortable in appearance. A small window looks out to the road."
    );
  SetSmell("The room is kept clean and free of dust.");
  SetListen("Random conversation fills the air at all hours.");
}