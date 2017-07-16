#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Town Headquarters");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetObviousExits("south, out");
  SetExits( ([
                  "south" : K_ROOM + "/bank",
                  "out" : K_ROOM + "/rd3" ]) );
  SetLong("This bunker-like room is extremely sturdy and massively "
          "constructed for durability and protection.  There is a "
          "huuuuge wooden desk here, and messengers are constantly "
          "passing to and fro, carrying out important city business. "
          "It is here that those wishing to become citizens of the "
          "mighty city Karak-Varn may apply for citizenship with the "
          "Warboss.  To the south, a tiny archway leads to what appears "
          "to be a bank of some sort.");
  SetInventory( ([ K_NPC + "/dealer" : 1,
                   K_NPC + "/rommel" : 1 ]) );
  SetNewsgroups( ({ "town.karak" }) );


}
