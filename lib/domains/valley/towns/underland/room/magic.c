/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Hall of Magic");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetExits( ([
    "out" : "road05",
    ]) );
  SetInventory( ([
    UNDER_NPC "evoker" : 1,
    UNDER_NPC "illusionist" : 1,
    ]) );
}