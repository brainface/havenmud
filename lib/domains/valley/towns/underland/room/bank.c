/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : "road07",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("inside the Bank");
  SetInventory( ([
    UNDER_NPC "banker" : 1,
    ]) );    
}