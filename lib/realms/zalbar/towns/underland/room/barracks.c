/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : "road09",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("inside the Barracks");
  SetInventory( ([
    UNDER_NPC "fighter" : 1,
    UNDER_NPC "guard"   : 2,
    ]) );
}