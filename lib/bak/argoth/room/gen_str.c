#include <lib.h>
#include "../argoth.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetNoClean(1);
    SetInventory( ([
    ARGOTH_OBJ + "pack.c" : 2,
    "/std/obj/light/torch.c" : 4,
    "/std/obj/light/match.c" : 4,
/*
    "/std/obj/fishing/pole.c" : 4,
*/
          "/std/fish/pole.c" : 4,
    ]) );
}
