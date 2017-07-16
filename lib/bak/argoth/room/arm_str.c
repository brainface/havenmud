#include "../argoth.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetNoClean(1);
    SetInventory( ([
    ARGOTH_OBJ + "smallshield.c" : 2,
    ARGOTH_OBJ + "largeshield.c" : 2,
    ]) );
}
