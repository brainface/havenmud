/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : "road09",
    "south" : "road07",
    "west"  : "cemetery",
    ]) );
  SetItems( ([
    "hospital" : "This is the local hospital.",
    ]) );
  SetEnters( ([
    "hospital" : UNDER_ROOM "healer",
    ]) );
}