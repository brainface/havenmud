#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(45);
  SetShort("inside a small building");
  SetSmell( ([
    "default" : "The smell of good food and ale fills the air.",
    ]) );
  SetListen( ([
    "default" : "Quiet conversation seems to whisper through the room.",
    ]) );
  SetLong("The inn of Tai-Ri is a small but prosperous place filled "
          "with low tables at which to eat. The walls are a thicker "
          "paper here, obviously treated against fire in the best ways "
          "the innkeep could afford.");
  SetItems( ([
    ({ "inn", "place", }) : (: GetLong :),
    ({ "table", "tables", "ground" }) : 
    	      "The tables are low to the ground, with no chairs. Diners must sit "
    	      "upon the floor to eat next to a table.",
    ({ "wall", "walls" }) : "The walls are made of a thick fire proof paper.",
    ]) );
  SetExits( ([
    "out" : "path4",
    ]) );
  SetInventory( ([
     TAI_RI_NPC "innkeep" : 1,
//     TAI_RI_NPC "citizen" : random(3),
     TAI_RI_NPC "equipper" : 1,
    ]) );
}
