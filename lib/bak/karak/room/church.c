#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Church of Saahagoth");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetObviousExits("out");
  SetExits( ([    "out" : K_ROOM + "/rd3" ]) );
  SetLong("Whoever designed this magnificent structure has managed to "
          "create a structure both durable and aesthetically pleasing.  "
          "candles line the walls leaving a soft and warm glow  "
          "and an aura of reverence.  It is here that devoted followers "
          "of Saahagoth may join the ranks of the clergy.  The only "
          "exit is to the south.");
  SetInventory( ([
    K_NPC + "/varag" : 1,
    K_NPC + "/nothleus" : 1
  ]) );

}
