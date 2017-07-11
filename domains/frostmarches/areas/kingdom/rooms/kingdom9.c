
/* a room in the kingdom
   Elasandria 4/15/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetShort("the guards' quarters");
  SetClimate("indoors");
  SetAmbientLight(45);
  SetLong(
    "A great banner, depicting one of the great faerie wars, covers one " 
    "wall. But other than that, it lacks any other decorations. The room "
    "has lots of hammocks and a few comfy looking chairs. It is obviously "
    "here that the kingdom's guards sleep."
  );
  SetItems( ([
    ({"hammock","hammocks","vine","vines"}) : "Lots of hammocks made of "
      "sturdy looking vines are strung around the room.",
    ({"chair","chairs"}) : "These plush chairs must look especially "
      "inviting after a hard day of protecting the queen.",
    "banner" : "This banner is embroidered with bold colored silk threads.",
    ({"thread","threads"}) : "The silk threads that make up the banner are "
      "dyed in brilliant primary colors.",
    "wall" : "One wall is covered in a beautifully created banner.",
  ]) );
  SetSmell( ([
    "default" : "A woody, masculine odor fills the quarters.",
  ]) );
  SetListen( ([
    "default" : "An occasional snore can be heard above the general "
      "noise in the room.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "guard1" : 1,
    KINGDOM_NPC + "guard2" : 2,
    KINGDOM_NPC + "guard3" : 1,
  ]) );
  SetExits( ([
    "out" : KINGDOM_ROOMS + "kingdom10",
  ]) );
}
