#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("jubbal's Smithy");
  SetLong(
    "The smithy is dimly lit by the light of the forge. "
    "All about the room are racks of weapons, and stacks "
    "of various metals. All of the completed weapons "
    "seem to be of very high craftsmanship."
  );
  SetItems( ([
    ({ "forge" }) : "The forge is a large structure that is big enough"
    " for a large creature to fit into.",
    ({"racks of weapons", "weapons", "racks"}) :
    "They all appear to be of superior quality.  ",
    ({ "various metals", "metals", "stacks" }) :
    "Bronze, copper, steel, iron, etc.",
  ]) );
  SetEnters( ([
    "forge" : G_ROOM + "forge",
  ]) );
  SetInventory( ([
    G_NPC + "jubbal" : 1,
  ]) );
  SetExits( ([ 
    "out" : G_ROOM + "road25" 
  ]) );
  SetProperties(  ([
    "metal repair" : 1,
    "natural repair" : 1,
    "wood repair" : 1,
    "leather repair" : 1,
    "textile repair" : 1,
    "mithral repair" : 1,
  ]) );
}

