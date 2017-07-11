#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "east" : PARVA_ROOM "wharf4",
    "west" : PARVA_ROOM "path2",
    ]) );
  SetShort("a small dirt road in Parva");
  SetLong(
    "The dirt path which runs through Parva from west to east here leads "
    "past a row of leaning, ramshackle buildings. One stout structure stands "
    "amongst the rest and appears to be some sort of store. The wharf "
    "protrudes out into the ocean governing the eastern horizon. "
  );
  SetItems( ([
    ({ "store", "structure" }) :
    "The General Store sits along the northern roadside.",
    "path" : "The dirt path is shabby, but appears to be the main road.",
    "buildings" :
    "The buildings lean against each other in an effort not to collapse.",
    "wharf" : "It is just to the east.",
    ]) );
  SetItemAdjectives( ([
    "path" : ({"dirt"}),
    "buildings" : ({"ramshackle", "leaning"}),
    "structure" : ({"stout"}),
    ]) );
  SetEnters( ([
    "store" : PARVA_ROOM "store",
    ]) );
  SetSmell("Something smells positively awful in this town.");
  SetListen("At all hours, Parva is alive with raucous noise.");
  SetInventory( ([
    PARVA_NPC "bard" : 1,
    ]) );
}

