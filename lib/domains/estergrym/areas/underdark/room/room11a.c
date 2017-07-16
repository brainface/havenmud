#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a very large chamber");
  SetLong("A very large chamber, the ceiling can not be seen in the "
         "darkness. The chamber extendeds further south. All around "
         "is a ramshackle camp of dwarven refugees. Several drooping "
         "tents and makeshift shelters provide protection from the water "
         "dripping from over head. Groups of desheveled dwarven "
         "citizens huddle around two small fires talking quietly about "
         "the horrors in the depths.");
  SetExits( ([
          "northeast" : U_ROOM + "room13a",
          "south" : U_ROOM + "room9a"]) );
  SetItems( ([
          "chamber" : "A very large chamber, the ceiling and walls are lost "
          "in darkness. The chamber extends further south.",
          ({ "camp", "ramshackle camp", "dwarven camp", "dwarf camp" }) :
          "A large camp of dwarven refugees. Drooping tents and leantos "
          "provide shelter. The dwarves huddle around small campfires "
          "wispering about the horrors in the depths.",
          ({ "tent", "tents", "shelter", "shelters", "makeshift shelters" }) :
         "Drooping tents and makeshift shelters are scattered about "
         "with no apparent pattern. The shelters protect their occupants "
         "from the ever present streams of dripping water falling from "
         "the ceiling.",
         ({ "water", "drip", "dripping water" }) : "Drip, Drip, Drip, Drip, "
         "Drip, Drip...........",
         ({ "fire", "fires", "small fire", "small fires" }) : "Several small fires "
         "are scattered about. Dwarven refugees huddle around the fires "
         "whispering quietly."]) );
 SetListen( ([
         "default" : "There is a constant, maddening, dripping sound."]) );
 SetInventory( ([
          U_NPC + "distraught_dwarf" : 3,
          U_NPC + "dwarf_soldier" : 2 ]) );
  }
