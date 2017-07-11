//
// mt3.c
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetShort("in the FrostMarches");
  SetLong("This snowy paradise is high in the FrostMarches. "
    "A steep cliff to the west looms over a large valley "
    "in the center. To the northwest, the mountain gets lower "
    "in altitude, while to the southwest, the mountain goes "
    "slightly higher into the sky.");
  SetItems( ([ ({ "snowy paradise", "paradise" }) : (: GetLong :),
    ({ "large valley", "valley" }) : "This large valley "
      "below sits deep "
      "in snow.",
    ({ "steep cliffs", "cliffs",
       "steep cliff", "cliff" }) : "This large cliff "
       "leads down into "
       "the large valley "
       "below.",
    ({ "mountain", "Marches", "mountains",
      "FrostMarches",
      "frostmarches" }) : "These large mountains get "
      "large to the southwest, but "
      "smaller to the northwest.",
    ({ "fluffy, white snow",
      "fluffy snow", "white snow","snow" }) : "This fluffy, "
      "white snow gently falls to the ground and piles up nicely.",
  ]));
  SetInventory( ([ NPC "/bear" : random(3) ]) );
  SetObviousExits("northwest, southwest");
  SetExits( ([ "northwest" : ROOM "/mt4",
    "southwest" : ROOM "/mt2" ]) );
}
