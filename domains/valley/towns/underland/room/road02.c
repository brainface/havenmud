/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : "road01",
    "east" : "road03",
    ]) );
  SetItems( ([
    "armoury" : "This is the local armoury.",
    ]) );
  SetEnters( ([
    "armoury" : UNDER_ROOM "armoury",
    ]) );
  SetDoor("west", UNDER_OBJ "door01");
}
