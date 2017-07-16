/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("inside the Armoury");    
  SetExits( ([
    "out" : "road02",
    ]) );
  SetInventory( ([
    UNDER_NPC "armourer" : 1,
    ]) );
}