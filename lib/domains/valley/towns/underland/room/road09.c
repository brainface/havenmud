/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "south" : "road08",
    ]) );
  SetItems( ([
    "barracks" : "This is the local barracks.",
    ]) );
  SetEnters( ([
    "barracks" : UNDER_ROOM "barracks",
    ]) );

}