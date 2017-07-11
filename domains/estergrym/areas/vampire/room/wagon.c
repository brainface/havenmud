//  Gypsy Caravan near Gothic Manor/Cemetery
//  Alessandra 2014

#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetShort("inside a gypsy wagon");
  SetLong(
     "There is stuff in here."
     );
  SetSmell( ([
     "default" : "It smells like stuff in here.",
     ]) );
  SetListen( ([
     "default" : "You can probably hear stuff in here.",
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
//     VAMP_NPC + "gypsy" : 1,
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
     "out" : VAMP_ROOM + "gypsycamp",
     ]) );

}
