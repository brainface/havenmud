// Coded by Zeratul
// 3-12-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("The Vacazar Bank");
  SetLong(
     "This large, stone building is an imposing site to see. The ceiling "
     "stands about two stories high, with large stone carvings "
     "in the walls and ceiling. A receptionist desk of sorts sits "
     "in the corner of the room. To the west the main foyer of the "
     "town hall can be seen. "
  );
  SetItems( ([
     ({"bank"}) : (:GetLong:),
     ({"carvings","walls","ceiling"}) : "The walls and ceiling appear "
     "to be covered with different kinds of carvings and sculptures. "
     "They look as if they are from the founders of this city, "
     "as if they tell the story of this city being created. ",
     ({"desk","receptionist desk"}) : "The stone desk sits in the corner "
     "of the room. Bank statements of sorts are piled up on the desk. ",
  ]) );
  SetItemAdjectives( ([
     "bank" : ({"large"}),
     "carvings" : ({"decorative"}),
     "desk" : ({"cluttered"}),
  ]) );
  SetListen( ([
     "default" : "The bank echoes with city life. ",
  ]) );
  SetSmell( ([
     "default" : "A musty smell hangs in the air. ",
  ]) );
  SetInventory( ([
     V_NPC + "vegor" : 1,
  ]) );
  SetExits( ([
     "west" : V_ROOM + "town_hall/th1",
  ]) );
  }
