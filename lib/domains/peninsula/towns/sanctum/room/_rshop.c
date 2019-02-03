#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../rome.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetInventory( ([
    ROME_OBJ "bpoison" : 5,
    ROME_OBJ "ypoison" : 10,
    ROME_OBJ "rpoison" : 10,
    ROME_OBJ "gpoison" : 15,
    ROME_OBJ "gvial" : 2,
    ROME_OBJ "fvial" : 20,

    ]) );
}
