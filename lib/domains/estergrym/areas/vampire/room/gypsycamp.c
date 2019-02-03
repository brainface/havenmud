//  Gypsy Camp near Gothic Manor/Cemetery
//  Alessandra 2014

#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("temperate");
  SetShort("a gypsy camp");
  SetLong(
     "A small clearing opens up here, the only path leading back out to "   
     "the northwest. The forest looms around the circled clearing as "
     "if trying to press in on it; leaving the distinct impression that there "
     "is someone or something keeping the forest in check here. A small campfire "
     "with a dutch oven has been set up in the center and beyond that sits a "
     "lone colorful wagon."
     );
  SetSmell( ([
     "default" : "The mouth watering smells of a stew waft up from the campfire.",
     ]) );
  SetListen( ([
     "default" : "The crackling of the fire is sharp in the otherwise silent forest.",
     ]) );
  SetItems( ([
     ({"clearing", "circle", "camp"}) : (:GetLong:),
     ({"path", "trail", "pathway"}) : "",
     ({"forest"}) : "",
     ({"tree", "trees"}) : "",
     ({"campfire"}) : "",
     ({"fire", "flames", "flame"}) : "",
     ({"oven", "pot"}) : "",
     ({"stew"}) : "",
     ({"center"}) : "",
     ({"wagon", "caravan"}) : "",  
     ]) );
  SetItemAdjectives( ([
     "clearing" : ({"small", "circled", "gypsy"}),
     "path" : ({"small"}),
     "forest" : ({""}),
     "tree" : ({""}),
     "campfire" : ({"small"}),
     "fire" : ({""}),
     "oven" : ({"dutch"}),
     "stew" : ({""}),
     "wagon" : ({"wood", "colorful"}),
     ]) );
  SetInventory( ([
     VAMP_OBJ + "wagon" : 1,
     ]) );
  SetEnters( ([
     ({"wagon", "caravan"}) : VAMP_ROOM + "wagon",
     ]) );
  SetExits( ([
     "northeast" : VAMP_ROOM + "forest14",
     ]) );

}
