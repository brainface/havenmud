/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the City Hall");
  SetClimate("indoors");
  SetAmbientLight(25);
  SetExits( ([
    "out" : UNDER_ROOM "road03",
    ]) );
  SetInventory( ([
    UNDER_NPC "mayor" : 1,
    ]) );
}