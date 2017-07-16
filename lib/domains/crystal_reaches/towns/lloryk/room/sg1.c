#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;


static void create() {
  room::create();

  SetShort("near the Southern Gate of Lloryk");
  SetExits( ([
     "north" : LLORYK + "room/sg2",
     "south" : LLORYK + "room/southgate"
    ]) );
            
  SetLong("The path continues to the north and south from here.  Off to the "
          "south, the path comes to a low wooden fence that serves as the "
          "town wall for Lloryk. The rolling hills of Lloryk spread out to "
          "the west and appear to always be ready for farming. Farther north "
          "the path meets up with Heroes Lane and meanders out of town.");
  SetSmell( ([
    "default" : "The smells of farm life are all around.",
    ]) );  
  SetItems( ([ 
    ({ "gate" }) : "The 'gate' is not much more than a few wooden planks "
                   "swinging in the opening in the short wooden fence.",
       "fence"   : "The fence looks to have been built more to keep "
                   "small children and animals in than anything else "
                   "out.",
    ({ "hill", "hills", "hillside" }) : "The rolling hills of Lloryk "
                                        "stretch out in all directions.",             
     ]));   
  SetItemAdjectives( ([
      "hill"   : ({ "rolling", }),
      "fence"  : ({ "low", "wooden" }),
    ]) );             
  SetListen( ([
    "default" : "The bleating of sheep comes from a local farm.",
    ]) );
}
