/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside a tavern");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "out" : "road01",
    ]) );
  AddExit("up", UNDER_ROOM "rogue");
  SetInventory( ([
    UNDER_NPC "barkeep" : 1,    
    ]) );
}