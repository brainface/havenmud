#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a pirate galleon");
  SetClimate("temperate");
  SetExits( ([
       "west" : ACOVE_ROOMS + "cove5",
       "down" : ACOVE_ROOMS + "cove11",
       ]) );
  SetLong("The temperature in this part of the "
        "ship is at least twenty degrees colder "
       "than anywhere else on the ship. "
        "The urge to flee before coming face to face "
        "with the evil that inhabits this place "
        "is very strong.");
  SetItems( ([
       ({ "ship","galleon"}) : (: GetLong :),
     ({ "gull", "gulls" }) : "Gray and white gulls are sleek "
                             "and well-fed.",
    ]) );
  SetInventory( ([
      ACOVE_NPC + "parrot" : 1,
     ]) );

}
