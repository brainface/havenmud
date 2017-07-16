/* a moat room
  kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the banks of a moat");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
        "north" : MANSION_ROOMS + "clearing5",
        "west" : MANSION_ROOMS + "moat3",
        "northeast" : MANSION_ROOMS + "clearing6",
        "northwest" : MANSION_ROOMS + "clearing4",
         ]) );
  SetListen( ([
       "default" : "A barking dog can be heard to the north.",
           ]) );
  SetSmell( ([
       "default" : "The stench of the moat is overwhelming",
         ]) );
  SetInventory( ([
              ]) );
  SetLong("The bank of the moat is quite muddy here. A large mansion "
         "lies to the south while to the east there appears to be a bridge."
       " The moat continues under the bridge to the east and around the "
      "corner of the mansion to the south. There appears to be a clearing "
     "to the north.");
  SetItems( ([
     "clearing" : "The clearing lies to the north of here.",
     "banks" : (:GetLong:),
      "moat" : "The stagnant water is an interesting shade of green.",
     "water" : "This water is covered in algea.",
    "algea" : "The small plants are green and cover the surface of the water.",
  ({"plants", "plant" }) : "This is algea.",
  "bank" : (:GetLong:),
       "mud" : "This mud is very sticky.",
       "mansion" : "This large structure is south of the moat.",
        "bridge" : "The bridge to the east crosses the moat's surface "
           "and there is no way to go under it. One would have to go "
          "north to cross the bridge.",
         "structure" : "This structure is a large mansion.",
        "surface" : "The surface of the moat is covered in little plants.",
        ]) );
  }
