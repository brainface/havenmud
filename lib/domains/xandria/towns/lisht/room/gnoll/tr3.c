//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("In front of the Temple");
  SetLong(
    "The beautiful Temple Road ends here at the expansive Enniae "
    "Temple, an inspired building made of glinting limestone and "
    "electrum, surmounted by a wall designed to keep those who "
    "would do harm to the clerics within out. The doors are wrought "
    "with heavy iron and bronze, each bearing the distinct scorpion "
    "emblem. The Temple Road leads north to the Palace, and an alley "
    "leads to the east. There also seems to be something to the west. "
    );
  SetItems( ([
    ({"door", "doors" }) : 
    "The doors to the temple are huge specimens of fortification, "
    "with scorpion symbols on the fronts.",
    ({ "temple" }) :
    "A fantastical building, walled off from the rest of Lisht and "
    "towering over the city.",
    ]) );
  SetInventory( ([
    LISHT_NPC "controller" : 1,
  ]) );
  SetExits( ([
   "north" : LISHT_ROOM "gnoll/tr2",
   "east" : LISHT_ROOM "gnoll/sa1",
   "west" : LISHT_ROOM "gnoll/graveyard",
    ]) );
  SetEnters( ([
  "temple" : LISHT_ROOM "gnoll/temple1",
    ]) );
  SetSmell("The scent of incense flows from the temple.");
}
