//  Alessandra 2011-2013

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road by the dock");
  SetLong(
     "The foot traffic is near constant this close to the docks, "
     "merchants hauling in new wares to take to the market, sailors "
     "headed back out to their ships or into town for a drink. The "
     "river Parsa runs along the east side of the road, cutting a "
     "path from the sea right down the middle of town. To the north "
     "are the docks and further south leads into the heart of Tameria. "  
     );
  SetSmell( ([
     "default" : "The air is crisp with the smell of sea spray.",
     ]) );
  SetListen( ([
     "default" : "Chatter from the docks can be heard here.",
     ]) );
  SetItems( ([
     ({"road", "ground", "floor", "spot"}) : "The dirt is well packed from "
       "heavy traffic from the docks. The road continues north to "
       "the dock and deeper within the town to the south.",
     ({"dirt"}) : "There's nothing special about this dirt. It's just "
       "as dusty and dirty as any other dirt in any other town.",
     ({"dock", "docks"}) : "The docks can be seen to the north where "
       "large sails rise up into the sky as captains and crews arrive "
       "and depart. ",
     ({"sail", "sails"}) : "White, and quite a few that were probably at one "
       "time white, sails pierce the sky to the north while ships large and "
       "small make port at the Tamerian docks. ",
     ({"ship", "ships"}) : "There are several ships to be seen from here "
       "but the view would be much better from the dock.",
     ({"river", "parsa", "path"}) : "The river Parsa is the life blood of "
       "Tameria. As myth tells, the river was a gift from the gods, "
       "cut from the sea to where the temple now stands.",
     ({"town", "heart", "tameria", "temple"}) : "Further exploration "
       "would be more prudent than trying to grasp the whole of Tameria "
       "from this specific spot of road.",
     ]) );
  SetItemAdjectives( ([
     "road" : ({"dirt", "packed", "specific"}),
     "dirt" : ({"packed", "dirty", "dusty"}),
     "sail" : ({"various", "white"}),
     "ship" : ({"several", "large", "small"}),
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
     "east" : TAM_ROOMR "river1",
     "north" : TAM_ROOM "dock1",
     "south" : TAM_ROOM "rw2",
     ]) );
}
