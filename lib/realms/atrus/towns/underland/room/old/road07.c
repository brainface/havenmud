/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : "road08",
    "south" : "road06",
    ]) );
  SetItems( ([
    "bank" : "This is the local bank.",
    ]) );
  SetEnters( ([
    "bank" : UNDER_ROOM "bank",
    ]) );
}