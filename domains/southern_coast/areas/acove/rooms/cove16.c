/*the crow's nest
 Zara 8/7/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("the crow's nest");

  SetClimate("temperate");


  SetExits( ([
    "down" : ACOVE_ROOMS + "cove4",
    ]) );

  SetLong("The view from here is panoramic. "
           "Overhead, suspended from a sturdy "
           "flagpole, flies a tattered skull and "
           "crossbones. The ghastly, smiling "
           "skull rests atop crossed thigh bones "
           "and sends a clear message to anyone "
           "unfortunate enough to encounter it.");

  SetItems( ([
      "view" : "The view from here is breathtaking.",
      "here" : "This is the crow's nest atop the ship.",
     "crows nest" : (:GetLong:),
     "flagpole" : "The pirate flag flies from this pole.",
     ({ "skull","bones" }) : "These bones make up the design "
                             "on the pirate flag.",
      ({"flag"}) : "The pirate flag is worn and tattered.",
       ({ "ship","galleon"}) : (: GetLong :),
     ]) );

  SetItemAdjectives( ([
  "view" : ({"panoramic","breathtaking"}),
 "skull" : ({"smiling","ghastly"}),
     ]) );

  SetSmell( ([
    "default" : "The wind carries a fresh salty tang.",
        ]) );

  SetListen( ([
    "default" : "Only the sound of gently lapping waves "
                "and an occasional gull cry can be heard. ",
        ]) );
  SetInventory( ([
      ACOVE_NPC + "lookout" : 1,
      ]) );
}
