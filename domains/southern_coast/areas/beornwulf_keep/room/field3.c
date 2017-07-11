#include <lib.h>
#include "path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("outside a huge keep");
    SetLong("The largest concentration of the orcs are here, laying siege to "
          "Lord Beornwulf's keep.  The humans have retreated inside the keep, "
          "and the orcs are now simply shutting them inside."
          "  The gates of the keep are slightly open, but the orcs have not "
          "entered.");
    SetItems( ([
          ({ "gates", "gate" }) :
          "The mighty gates of the keep are shattered and slightly open, "
          "but the human forces have somehow prevented the orcs from entering.",
          ({ "orcs" }) :
          "The orcs press relentlessly against the gates.",
          ({ "cold, stone walls", "cold stone walls", "stone walls",
          "cold walls,", "walls", "wall" }) :
          "The cold, stone walls of the keep are hard and lifeless.",
          ({ "ground" }) :
          "The ground is spattered with blood and gore.",
          ({ "keep of lord beornwulf", "huge keep", "keep" }) :
          "The keep of Lord Beornwulf is huge and ominous.",
          ]) );
    SetExits( ([
          "north" : BEORN_ROOM + "field2.c",
          ]) );
    SetEnters( ([
          "keep" : BEORN_ROOM + "gatehouse.c",
          "gate" : BEORN_ROOM + "gatehouse.c",
           ]) );
    SetObviousExits("north");
    SetInventory( ([
          BEORN_NPC + "osoldier.c" : 3,
          ]) );
    SetListen( ([
          "default" : "The terrible sounds of battle fill the air.",
]) );
}
