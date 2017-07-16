#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
     AVERATH_OBJ "torch" : 1,
     AVERATH_OBJ "match" : 3,
     ]) );
/*  This is the storage room for the local shop. */

}
