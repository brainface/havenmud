
//  Alessandra 2011-2013

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("the western dock");
  SetLong(
     "Sturdy docks line either side of the river Parsa where it carves its "
     "path inland from the Southern Sea, giving port. Here, on the western "
     "docks, one can find passage to distant lands or meet the incoming "
     "vessels. To the east is the inlet of the river and south leads "
     "down the western road through town. "
     );
  SetSmell( ([
     "default" : "The crisp, salty air is carried in from the sea.",
     ]) );
  SetListen( ([
     "default" : "Gulls caw overhead, giving punctuation to the bustling "
        "dockyard. ",
     ]) );
  SetItems( ([
     ({"dock", "docks", "port", "wharf", "quay", "dockyard"}) :
       "The docks jut out into the Southern Sea, giving port to ships "
       "large and small. Their construction is a combination of sturdy "
       "stone and wood.",
     ({"river", "parsa"}) : "The river Parsa is the life blood of "
       "Tameria. As myth tells, the river was a gift from the gods, "
       "cut from the sea to where the temple now stands.",
     ]) );
  SetItemAdjectives( ([
     "dock" : ({"sturdy", "wood", "stone"}),
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
//     "north" : the sea,
     "south" : TAM_ROOM "rw1",
//     "east" : the river inlet 
     ]) );
}
