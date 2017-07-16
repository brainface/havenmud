// Coded by Zeratul
// 3-12-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("The Vacazar Town Hall");
  SetLong(
     "This large, stone building is an imposing site to see. The foyer "
     "stands about two stories high, with large stone carvings in the "
     "walls and ceiling. A stone desk sits in the middle of the room, "
     "which looks to be cluttered with all sorts of objects. "
     "To the east appears to be the bank of the city, and to the south "
     "there appears to be a merchant's quarters. "
  );
  SetItems( ([
     ({"town hall"}) : (:GetLong:),
     ({"carvings","walls","ceiling"}) : "The walls and ceiling appear "
     "to be covered with differant kinds of carvings and sculptures. "
     "They looks as if they are from the founders of this city, "
     "as if they tell the story of this city being created. ",
     ({"desk","clutter"}) : "The stone desk sits in the middle of the "
     "room. All sorts of clutter is on the desk top, ranging from "
     "work orders, to requests for citizenship. ",
  ]) );
  SetItemAdjectives( ([
     "town hall" : ({"stone","large"}),
     "carvings" : ({"unique","fancy"}),
     "desk" : ({"cluttered"}),
  ]) );
  SetListen( ([
     "default" : "The town hall echoes with city life. ",
  ]) );
  SetSmell( ([
     "default" : "A musty smell hangs in the air. ",
  ]) );
  SetInventory( ([
     V_NPC + "barzurar" : 1,
  ]) );
  SetExits( ([
     "out" : V_ROOM + "main_road/mr4",
     "east" : V_ROOM + "town_hall/th2",
     "south" : V_ROOM + "town_hall/th3",
  ]) );
  }
