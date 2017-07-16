// Urien 111313 - Added Day/Night Long
// Climate, Town, Domain, Items, Adjectives
// Kept overall description the same.

#include <lib.h>
#include <domains.h>
#include "../goblins.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Southern Coast");
  SetTown("Kresh");
  SetShort("a bend in the main path");
  SetDayLong("The main path bends to the south and "
     "reaches northeast. Numerous tents border the "
     "path with their entrances facing away from "
     "visible access. A small dingy tent with a "
     "sign posted outside the entrance can be "
     "seen to the northwest. The barren field "
     "shines in the daylights essence.");
  SetNightLong("Several tents border off the main "
     "path which lead in separate directions into "
     "the Goblin village. A single dingy tent can "
     "be seen to the northwest with the entrance "
     "easily displayed. The night casts its "
     "absence of light over the barren field and "
     "the vacant path that provides passage.");
  SetItems( ([
   ({ "field","village" }): (: GetLong :),
   ({ "ground", "floor" }): "It has packed soil that "
        "has accrued since the nomads made this their "
        "home. A main dirt path can be seen bending "
        "into different directions.",
  "tent" : "The dingy tent is quite small. It was "
    "made with a thick white linen which has dirt "
    "and dust stains along the outside surface. "
    "It looks fairly secure to withstand the natural "
    "elements of the Southern Coast. A sign has been "
    "posted near the entrance that faces southeast "
    "toward the main path. It is fairly quiet and "
    "humble.",
   "tents": "All of the brown tents have been built to "
    "face away from the main path, with their separate "
    "entrances out of sight. They are clustered together "
    "and border off all but two directions in the field. "
    "A more official tent sits northwest of the path "
    "appealing to visitors.",
   "path": "The main dirt path leads off into separate "
    "directions in Kresh. It is bordered off by the many "
    "tents that sit clustered in this part of the village.",
   "sign": "The sign has a picture of a quill etched into "
    "the sun bleached driftwood. It has been hung outside "
    "the dingy white tent entrance.",
   "entrance": "A single entrance appears to be an open "
    "invitation to the white tent. A sign made of driftwood "
    "hangs near it, displaying the tents official intention.",
   "bend": "The bend in the main path leads into "
    "different directions.",
  ]) );
  SetItemAdjectives( ([
   "tent": ({ "small","dingy","white","official" }),
   "tents": ({ "brown","" }),
   "path": ({ "main","dirt" }),
   "field": ({ "barren" }),
   "entrance": ({ "tent" }),
  ]) );
  SetRead("sign", "The sign has only pictures on it.");
  SetSmell( ([
     "default" : "The path smells of waste and offal.",
  ]) );
  SetListen( ([
     "default" : "The sounds of the goblin village are "
      "quieter here.",
  ]) );
  SetInventory( ([
     GOBLIN_NPC + "medium" : 3,
  ]) );
 
  SetEnters( ([
    "tent" : GOBLIN_TENT "office",
  ]) );
  SetExits( ([
     "northeast" : GOBLIN_ROOM + "m_3",
     "south" : GOBLIN_ROOM + "m_6",
  ]) );
}