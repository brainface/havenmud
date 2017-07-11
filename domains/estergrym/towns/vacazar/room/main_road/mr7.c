// Coded by Zeratul
// 3-11-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("the main road in town");
  SetLong(
     "The tunnel leads into an open cavern, revealing an underground city. "
     "Differant kinds of stone buildings stand along either side of the "
     "road. "
     "To the north is the main intersection of the town, where "
     "the town hall stands. To the south the church can be seen. "
  );
  SetItems( ([
     ({"town","cavern"}) : (:GetLong:),
     ({"town hall","hall"}) : "This large building has been carved directly "
     "out of the rock of the mountain. The building stands to the north. ",
     ({"buildings","stone buildings"}) : "Differant kinds of stone "
     "buildings stand along either side of the road, shops, homes, "
     "and businessess. ",
     "church" : "To the south the Church of Skadar stands over the road. "
     "The large stone building appears to have been carved out of the "
     "rock of the mountains. ",
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
  SetSmell( ([
     "default" : "The underground city smells of city life. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "north" : V_ROOM + "main_road/mr6",
     "south" : V_ROOM + "main_road/mr8",
  ]) );
  }
