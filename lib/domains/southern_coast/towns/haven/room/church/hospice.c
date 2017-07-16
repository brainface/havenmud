//
// Filename: hospice.c
// The Haven Town Hospice
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the Hospice of Haven Town");
   SetExits( ([
      "south" : "entrance",
   ]) );
   SetLong("The hospice of Haven Town is a small and efficient place of "
           "healing dedicated to the Lord of Order. His divine will can "
           "be felt like a presence here, even without the huge symbol "
           "of the Scales and Dragon which hangs on the wall like "
           "a watchful guardian over the wounded. To the south is the "
           "main entrance to the Temple.");
   SetItems( ([
      ({ "symbol", "symbol of kylin", "guardian" }) :
         "The huge symbol of Kylin, a set of Balance Scales with "
         "a Red Dragon wrapped around it, hangs on the wall like "
         "a terrible guardian.",
      ({ "presence" }) :
         "The presence of the Lord of Kylin can be felt here.",
      ({ "entrance" }) :
         "The main entrance to the temple is located to the south of "
         "here",
      ({ "temple" }) :
         "The temple can be seen to the south",
   ]) );
   SetItemAdjectives( ([
      "symbol" : ({ "huge", "watchful" }),
      "entrance" : ({ "main" }),
   ]) );
   SetListen( ([
      "default" : "The quiet suffering of the wounded fills the air.",
   ]) );
   SetSmell( ([
      "default" : "The smells of healing herbs wafts like a cool wind.",
   ]) );
   SetInventory( ([
      H_NPC + "healer" : 1,
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:38:06 1999. */
