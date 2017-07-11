// Coded by Zeratul
// 3-22-2000

#include <lib.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("the Vacazar Smithy");
  SetLong(
     "This is the local town smithy. The walls are dark and full of ashes. "
     "There is a large forge over in the corner, with molds and other objects. "
     "There is a small desk that sits in the opposite corner, where by the "
     "money is handled with the customers. Out of the shop leads back into "
     "the main road in town. "
  );
  SetItems( ([
     ({"smithy","shop"}) : (:GetLong:),
     ({"forge","molds","objects","equipment"}) : "In the corner stands a "
     "large, hot metal forge. On it lies a piece of a weapon that is being "
     "forged into a weapon. Around the forge lies molds for the weapons, "
     "as well as other smither's tools. ",
    ({"desk"}) : "This desks sits in the corner opposite from the forge. This "
     "is where the customers to the shop handle money with the smith who "
     "works here. ",
  ]) );
  SetItemAdjectives( ([
     "smithy" : ({"ashen","dark"}),
     "forge" : ({"hot","metal","large"}),
     "desk" : ({"stone"}),
  ]) );
  SetListen( ([
     "default" : "The sounds of striking hammers against metal echoes thoughout "
     "the room. "
  ]) );
  SetSmell( ([
     "default" : "The smell of molten metal and hot ashes fills the air. "
  ]) );
  SetInventory( ([
     V_NPC + "mazac" : 1,
  ]) );
  SetExits( ([
     "out" : V_ROOM + "main_road/mr5",
  ]) );
  }
