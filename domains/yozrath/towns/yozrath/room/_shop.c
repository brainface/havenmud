#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetInventory( ([
    YOZRATH_VIRTUAL "obj/waterskin"    : 50,
    YOZRATH_OBJ     "desertrose"       : 10,
    YOZRATH_VIRTUAL "obj/kopesh"       : 2,
    STD_CLOTHING    "body/dbrown_robe" : 1,
    STD_CLOTHING    "body/green_robe"  : 1,
    STD_LIGHT       "torch"            : 10,
    STD_FISHING     "pole"             : 1,
    STD_OBJ         "digging/shovel"   : 2,
    ]) );
}
