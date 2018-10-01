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
           "east"      : HIVE_ROOM "room34",
           "south"      : HIVE_ROOM "room36",
           ]) );
         }
