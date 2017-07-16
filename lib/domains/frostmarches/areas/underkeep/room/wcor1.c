//
// a corridor
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetShort("a black and white corridor");
  SetLong("This passage meanders from east to west, following a course "
    "that only a lunatic or a genius would come up with. The ceiling "
    "is tiled with tiny black and white squares. Some of these have "
    "come off in places, revealing the bare stone above. The walls "
    "themselves are of a plain stone, unworked by mortal hands.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    ({"passage","corridor"}) : (:GetLong:),
    ({"ceiling","tiles","tile","square","squares"}) :
      "The ceiling tiles are of black and white marble.",
    ({"walls","wall","stone","granite"}) :
      "The stone of the walls, and in places, the ceiling, is gray and "
      "hard, probably granite.",
    "dust" : "Dust covers all the surfaces.",
    ]) );
    SetItemAdjectives( ([
      "stone" : ({"bare","plain"}),
      "wall" : ({"stone","grey","hard"}),
      "tiles" : ({"ceiling","black","white","tiny","marble"}),
      ]) );
  SetSmell( ([
    "default" :
      "The dusty smell of a long-abandoned home fills the air.",
    "dust" :
      "The dust smells of wood and rotting vegetables.",
    ]) );
  SetListen( ([
    "default" :
      "Faint scratching can be heard to the west.",
     ]) );
  SetInventory( ([
    ]) );
  SetExits( ([
    "west" : RNQ_RM + "wcor2.c",
    "east" : RNQ_RM + "forect.c",
    ]) );
}
