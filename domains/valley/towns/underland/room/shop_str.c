

/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetInventory( ([
    STD_LIGHT "torch" : 12,
    ]) );
}
