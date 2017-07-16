// Coded by Zeratul
// 3-11-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("The intersection of Fighter Road and the main road");
  SetLong(
     "The road leads into an intersection here. Differant kinds of "
     "stone buildings stand along either side of the road. The town hall "
     "stands "
     "over the road to the east, while fighter road leads to the west. "
     "The main road leads to the south, where the church can be seen. "
  );
  SetItems( ([
     ({"town","cavern"}) : (:GetLong:),
     ({"town hall","hall"}) : "This large building has been carved directly "
     "out of the rock of the mountain. The building stands to the east. ",
     ({"buildings","stone buildings"}) : "Differant kinds of stone "
     "buildings stand along either side of the road, shops, homes, "
     "and businessess. ",
     ({"road","tunnel"}) : "The tunnel opens up into a the large cavern, "
     "where the road starts. The road looks to be well used and travelled "
     "upon. The road leads to the south and to the north. ",
  ]) );
  SetItemAdjectives( ([
     "town hall" : ({"stone","large"}),
     "buildings" : ({"large","various","stone"}),
     "cavern" : ({"large","open"}),
     "road" : ({"worn"}),
  ]) );
  SetListen( ([
     "default" : "The sounds of civilization echoes throughout the city. ",
  ]) );
  SetEnters( ([
     "town hall" : V_ROOM + "town_hall/th1",
  ]) );
  SetSmell( ([
     "default" : "The underground city smells of city life. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
      "north" : V_ROOM + "main_road/mr3",
      "south" : V_ROOM + "main_road/mr5",
  ]) );
  }
