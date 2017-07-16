//Selket@Haven
//2006
#include <lib.h>
#include "../../lisht.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a study area");
  SetClimate("indoors");
  SetAmbientLight(45);
  SetExits( ([
      "west" : "lib1",
      "up" : "lib4",
      "out" : "sa2",
   ]) );
  SetLong(
    "This is a quiet area those who work at the Great Library use for "
    "study and meditation. The floor is lined with soft, thick rugs "
    "and strewn with cushions to lean on, and the light here seems a "
    "bit more subdued. The upper recesses of the ceiling have small "
    "grates to let in the outside air, keeping the air in this room "
    "fresh and clean, and the breeze stirs a few chimes hidden in the "
    "rafters. There is a staircase leading upwards here, and an "
    "imposing archway just to the west.");
  SetItems( ([
    ({ "rugs", "rug", "cushion", "cushions," "floor" }) :
        "The rugs and cushions are luxuriously soft and spongy, "
        "and appear very comfortable.",
    ({ "necromancer", "necromancers", "evokers", "evoker" }) :
        "The specialized halls seem to be upstairs.",
    ({ "grate", "grates", "ceiling", "recesses", "rafters" }) :
        "The small metal grates in the ceiling allow for air here to "
        "circulate.",
    ({ "archway", "arch", "door" }) : 
        "The monstrous doorway leads into the west.",
    ({ "window", "windows", "glow", "light" }) :
        "The light source of this room comes from pink tinted windows "
        "and the occasional oil lamp.",
    ({ "staircase", "stairs" }) :
        "A sturdy-looking staircase leads to the specialized halls. ",
  ]) );
  SetItemAdjectives( ([
    "window" : ({ "rose", "rose-colored" }),
    "rug" : ({ "soft", "thick" }),
    "light" : ({ "subdued" }),
    "recesses" : ({ "upper" }),
    "archway" : ({ "imposing" }),
  ]) );
  SetSmell( ([
    "default" : "The air is fresh and clean smelling.",
  ]) );
  SetListen( ([
    "default" : "The soft tinkle of wind chimes can faintly be heard. ",
   ]) );
  SetInventory( ([
    LISHT_NPC + "sheftu" : 1,
   ]) );
}
