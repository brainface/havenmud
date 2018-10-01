// Urien 111213 - Added Day/Night Long
// Climate, Town, Domain, Items, Adjectives
// Kept overall description the same.

#include <domains.h>
#include <lib.h>
#include "../goblins.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Southern Coast");
  SetTown("Kresh");
  SetShort("a main path fork in Kresh");
  SetDayLong("The main path divides, splitting to the "
     "southeast and the southwest. In both directions "
     "there are several tents which house life in the "
     "village. A small brown tent with ebony tusks "
     "sticking out of the corners has a sign posted "
     "near the entrance. This fork in the path is "
     "crowded with tents and border off the streets "
     "in different directions.");
  SetNightLong("The main path splits from the north "
     "and splits to the southwest and southeast. This "
     "section of the main path is crowded with tents "
     "from the Goblin nomads. A small tent which has "
     "an unilluminated sign posted along the entrance "
     "can be seen. Darkness casts its shadow over the "
     "sparsely glowing tents which border the path "
     "and lead in different directions in the village.");
  SetItems( ([
   ({ "path","fork" }): (: GetLong :),
   ({ "ground", "floor" }): "The ground is merely packed "
      "dirt trampled from the nomad inhabitants. It is "
      "devoid of any life and the exposed Kailie soil "
      "is barren. The path has been beaten into it "
      "from years of nomads trampling it.",
   "tents": "Several tents have been built along this "
      "section of Kresh. All appear of the same design, "
      "vice the small brown tent at the apex of the fork.",
   "tusks": "Small tusks reaved from a boar seem to have "
      "been used to highlight the small tent. They look "
      "fairly yellowed from age and exposure.",
   "smoke": "White smoke seeps from the small tents "
      "exhaust hole in the top and dissipates into the "
      "air. It looks to be a controlled heating source "
      "and not a tent fire.",
   "entrance": "A single entrance can be seen facing the "
      "main path with a sign next to it. It looks rather "
      "inviting.",
   "tent" : "The tent has a small hole in the top letting "
      "smoke out. The exterior is square and made with "
      "a thick brown cloth. Tusks have been tied to each "
      "corner to highlight the tent business.",
   "sign" : "The sign has pictures of mugs and a drumstick. "
      "It looks to have been a piece of driftwood that is "
      "being used as a highlight to invite potential guests.",
  ]) );
  SetItemAdjectives( ([
   "tent": ({ "small","brown" }),
   "tents": ({ "small" }),
   "smoke": ({ "white" }),
   "tusks": ({ "boar","yellow" }),
   "sign": ({ "wooden" }),
  ]) ); 
  SetEnters( ([
     "tent" : GOBLIN_TENT + "inn",
  ]) );
  SetRead("sign", "The sign has only pictures on it.");
  SetSmell( ([
     "default" : "The village smells of rotting food and offal.",
  ]) );
  SetListen( ([
      "default" : "Goblin banter can sometimes be heard.",
  ]) );
  SetExits( ([
    "southeast" : GOBLIN_ROOM + "m_5",
    "east"      : GOBLIN_ROOM + "cem",
    "southwest" : GOBLIN_ROOM + "m_4",
    "north"     : GOBLIN_ROOM + "m_2",
  ]) );
  SetInventory( ([
     GOBLIN_NPC + "karkaradon" : 1,
  ]) );
}