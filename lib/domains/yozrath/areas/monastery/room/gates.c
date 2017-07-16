// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <domains.h>
#include "../monastery.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("arid");
  SetShort("before the gates of a stone monastery");
  SetLong(
    "The desert ends here at the base of a towering stone wall to the "
    "north. It looks ancient and worn but seems very capable of defending "
    "against invaders and, more likely, the harsh sandstorms which "
    "occasionally frequent the area. A huge wooden gate leads through "
    "the wall to what seems to be a place of worship. The symbol of the "
    "Kylin faith, the balance entwined with a dragon, is carved into the "
    "stonework above the gate. A dusty path to the southeast leads to the "
    "Yozrath desert."
  );
  SetItems( ([
  ({ "wall" }) :
    "The huge wall surrounds the monastery. It�s bricks are beginning "
    "to crumble a little, but it still looks more than capable at "
    "keeping out unwanted guests.",
  ({ "gate" }) :
    "The gate is open, welcoming all visitors to the monastery. ",
  ({ "symbol", "dragon", "balance" }) :
    "The balance entwined with a dragon is the "
    "symbol of the Kylin faith. It is clear that the monastery is for "
    "those of that faith to worship in.",
  ({ "stonework" }) :
    "There is a large symbol engraved in the stone above the gate.",
  ({ "desert" }) :
    "The Yozrath desert spreads out to the southeast. To the north, "
    "it ends at the base of a towering stone wall.",
  ({ "path" }) :
    "The dusty path leads southeast to the Yozrath desert.",
  ]) );
  SetItemAdjectives( ([
    "wall" : ({ "towering", "stone" }),
    "gate" : ({ "huge", "wooden" }),
    "path" : ({ "dusty" }),
  ]) );
  SetInventory( ([
    AREA_NPC "guard" : 2,
  ]) );
  SetListen( ([
    "default" : "The sounds of deep chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The smell of wine and incense is carried on the air from the north.",
  ]) );
  SetExits( ([
    "north" : AREA_ROOM "courtyard",
    "southeast" : "/domains/yozrath/virtual/desert/40,100",
  ]) );
}
