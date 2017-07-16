#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Karak-Varn Arms, Armours, and Goods");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetObviousExits("out");
  SetExits( ([ "out" : K_ROOM + "/rd5" ]) );
  SetInventory( ([ K_NPC + "/grond" : 1 ]) );
  SetLong("This shop is dominated by a large wooden counter behind "
          "which the shopkeep buys and sells merchandise.  The room "
          "is very hot, which suggests that a forge may be in the next "
          "room.  All over the shop are large racks and bins for holding "
          "the assorted selection of goods.");

}
