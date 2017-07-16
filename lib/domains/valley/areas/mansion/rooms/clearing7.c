/* a clearing
   kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small clearing");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
      "south" : MANSION_ROOMS + "moat5",
      "east" : MANSION_ROOMS + "clearing8",
      "west" : MANSION_ROOMS + "clearing6",
      "southeast" : MANSION_ROOMS + "moat6",
           ]) );
  SetInventory( ([
       CLEARING_NPC + "hummingbird" : 2,
             ]) );
  SetListen( ([
       "default" : "Barking dogs can be heard to the west.",
           ]) );
  SetSmell( ([
       "default" : "There is a very foul odor coming from the south.",
          ]) );
  SetLong("The grass is long here and the landscape is speckled with "
         "small flowers and bushes. The clearing extends on to the east "
         "and to the west, while to the south there appears to be a small "
         "body of water.");
  SetItems( ([
      "grass" : "The long grass is very plentiful here.",
      "clearing" : (:GetLong:),
      "landscape" : "The landscape has scattered bushes and flowers throughout.",
    ({"flower", "flowers"}) : "These flowers are very pretty.",
      ({"bush", "bushes"}) : "The bushes look very prickly.",
         "water" : "The water lies to the south.",
         ]) );
  }
