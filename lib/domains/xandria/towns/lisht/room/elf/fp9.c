#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west"  : LISHT_ROOM "elf/rr1",
    "east"  : LISHT_ROOM "elf/fp7",
    ]) );
  SetShort("the floodplain of the River Itro");
  SetLong(
    "The river floods here routinely every year, filling the small plain "
    "with water and creating a fertile area for crops. To the east lies the "
    "river Itro, the heart and soul of the Xandrian Dynasty that rules these "
    "lands. The River Road lies to the west, a small path leading through "
    "the elven section of Lisht. A small but tidy house sits along the road."
    );
  SetSmell("The floodplains smell of wet mud and growing vegetation.");
  SetListen("The waves of the river gently crash against the shore.");  
  SetItems( ([
    "river" : "The River Itro extends to the north and south. To the north "
              "it leads out to the Southern Sea, while to the south it heads "
              "off to Lake Rantera.",
    "house" : "The house is the home of a local elven musician.",
    ]) );  
  SetEnters( ([
    "house" : LISHT_ROOM "elf/singer",
    ]) );
}
