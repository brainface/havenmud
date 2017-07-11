#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside Pons' General Store");
  SetExits( ([
    "out" : PARVA_ROOM "path3",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    PARVA_NPC "shopkeep" : 1,
    ]) );
  SetLong(
    "This is the Parvan General Store. Behind an oaken, yet shorter than "
    "normal, counter stand waxed wooden shelves lined with a multitude of "
    "goods for purchase. Hanging from the rafters on long chains are dusty "
    "but efficient oil lamps, which shine orangely at all hours of the day "
    "to cast what the shopkeep hopes is a cheery glow that will encourage "
    "citizens to buy."
    );
  SetSmell("The room has a faint smell of rotting fish and fish bait.");
  SetItems( ([
    "counter" : "This would be a normal shop counter for Parva were it not "
                "only three feet tall. It is apparent that the shopkeep is smaller "
                "than human size.",
    ({ "shelf", "shelves" }) : "The shelves stand idly to show their wares.",
    ({ "rafter", "rafters" }) : "Even the rafters are used to display goods.",
    ({ "lamp", "lamps" }) : "The lamps cast a bright and cheerful glow.",
    ]) );
  SetItemAdjectives( ([
    "counter" : ({ "oaken", "short" }),
    "shelf"   : ({ "waxed", "wooden" }),
    ]) );
}