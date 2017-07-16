#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "north" : LISHT_ROOM "elf/fp7",
    "east"  : LISHT_ROOM "elf/fp4",
    ]) );
  SetShort("the floodplain of the River Itro");
  SetLong(
    "The river floods here routinely every year, filling the small plain "
    "with water and creating a fertile area for crops. To the east lies the "
    "river Itro, the heart and soul of the Xandrian Dynasty that rules these "
    "lands. The city wall lies off to the south across an open field."
    );
  SetSmell("The floodplains smell of wet mud and growing vegetation.");
  SetListen("The waves of the river gently crash against the shore.");  
  SetItems( ([
    "river" : "The River Itro extends to the north and south. To the north "
              "it leads out to the Southern Sea, while to the south it heads "
              "off to Lake Rantera.",
    ]) );  
    
}
