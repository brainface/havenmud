#include <lib.h>
#include <domains.h>
#include <std.h>

inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
     STD_LIGHT "torch" : 5,
     ]) );

/*  This is the storage room for the local shop. */

}

