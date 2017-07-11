/* a bridge for the moat
    kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a wooden bridge");
SetDomain("Valley");
  SetClimate("temperate");
  SetInventory( ([
             ]) );
  SetExits( ([
         "north" : MANSION_ROOMS + "clearing6",
         "south" : MANSION_ROOMS + "2a",
           ]) );
  SetListen( ([
     "default" : "Noises can be heard from inside the mansion.",
          ]) );
  SetSmell( ([
       "default" : "The stench of the moat water is strong here.",
          ]) );
  SetLong("This wooden bridge looks very sturdy. There is a clearing "
            "to the north and the entrance to the mansion is to the south. "
           "There are rails on the sides of the bridge preventing one from "
           "falling into the moat.");
  SetItems( ([
       "bridge" : (:GetLong:),
       "clearing" : "The clearing is north of the bridge.",
  ({"mansion", "dwelling"}) : "This expansive dwelling obviously belongs "
                              "to a very wealthy person. For now, "
                             "there is no way in.",
       "entrance" : "A large door blocks the way into the mansion.",
      "door" : "This wooden door is very large and decorated elaborately",
  ({"rail", "rail"}) : "These wooden rails prevent anyone from falling "
                      "into the moat below.",
  ({"side", "sides"}) : "The sides of the bridge are protected by rails.",
      "moat" : "The moat lies below the bridge and cannot be seen from here.",
    "water" : "The water lies below the bridge and cannot be seen from here.",
            ]) );
  }
