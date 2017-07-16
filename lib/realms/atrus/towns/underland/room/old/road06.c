/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : "road07",
    "south" : "road03",
    ]) );
  SetItems( ([
    "shop" : "This is a general store selling most things needed.",
    ]) );
  SetEnters( ([
    "shop" : UNDER_ROOM "shop",
    ]) );
}