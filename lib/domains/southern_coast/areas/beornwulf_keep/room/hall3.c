#include <lib.h>
#include "path.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetShort("a dark hallway");
    SetLong("This is easily the gloomiest part of the keep of Lord Beornwulf. "
          "There is less light here than in the other rooms, and the air "
          "is thick and foreboding.  To the north is the main hall, and to the "
          "south is Lord Beornwulf's war room.");
    SetExits( ([
          "north" : BEORN_ROOM + "hall1.c",
          "south" : BEORN_ROOM + "warroom.c",
           ]) );
    SetObviousExits("north, south");
    SetInventory( ([
          BEORN_NPC + "hsoldier.c" : 2,
           ]) );

    SetItems( ([
          ({ "hallway", "hall" }) :
          "The hall is shrouded in darkness.",
]) );
    SetClimate("indoors");
    SetAmbientLight(30);
}
