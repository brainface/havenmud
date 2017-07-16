/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : "road03",
    "east" : "road05",
    ]) );
  SetItems( ([
    "hall" : "This is the Meeting Hall, a place for gnomes to gather and talk.",
    ]) );
  SetEnters( ([
    "hall" : UNDER_ROOM "newbie",
    ]) );
}