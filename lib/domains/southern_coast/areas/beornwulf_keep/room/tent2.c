#include <lib.h>
#include "path.h"
inherit LIB_ROOM;
static void create () {
    room::create();

    SetShort("the mauler's tent");
    SetLong("This is the tent where the infamous and bloodthirsty Sklaag the "
          "Mauler has taken residence during his siege on Beornwulf's keep. "
          "It is evident that only a few soldiers are permitted in the tent, "
          "as Sklaag is known for his quick temper and unpredictable actions.");
    SetItems( ([
          ({ "the mauler's tent", "mauler's tent", "tent" }) :
          "The tent is dark and exudes a sense of anger.",
          ]) );
    SetExits( ([
          "east" : BEORN_ROOM + "tent1.c",
]) );
    SetObviousExits("east");
    SetClimate("indoors");
    SetAmbientLight(45);
    SetInventory( ([
          BEORN_NPC + "orccaptain.c" : 1,
]) );
}
