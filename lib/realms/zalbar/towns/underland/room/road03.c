/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : "road02",
    "east" : "road04",
    "north": "road06",
    ]) );
  SetItems( ([
    "hall" : "This building serves as the City Hall for the Underland.",
    ]) );
  SetEnters( ([
    "hall" : UNDER_ROOM "city_hall",
    ]) );
  SetInventory( ([
    UNDER_NPC "citizen" : 2,
    UNDER_NPC "guard"   : 1,
    UNDER_OBJ "clock"   : 1,
    ]) );
}