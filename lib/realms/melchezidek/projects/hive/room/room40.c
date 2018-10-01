#include <lib.h>
#include <std.h>
#include "../hive.h"
inherit LIB_ROOM;

static void create() {
        ::create();
        SetClimate("underground");
        SetAmbientLight(0);
        SetShort("the Queen's Mine");
        SetLong(""
          );
        SetInventory( ([
            HIVE_OBJ "largecrystal"    : 1,
            ]) );
        SetExits( ([
           "north"      : HIVE_ROOM "room39",
           "up"         : HIVE_SOUTH_EXIT,
           ]) );
         }

