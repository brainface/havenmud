//
// The Southern End of the Training Hall
// Filename: south_library.c
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
   SetShort("the southern training halls");
   SetLong("This section of the Library is dedicated to the study of "
           "raw energy magic. To the east is the hall of the Enchanters, "
           "while to the west is the hall of the Evokers. Further north "
           "lies the main chamber of research and the path out of the "
           "library. ");
   SetExits( ([
      "north" : "training_hall",
      "east" : "enchanters",
      "west" : "evokers",
   ]) );
   SetItems( ([
      ({ "enchanter", "enchanters" }) :
         "To the east lies the training halls of the enchanters.",
      ({ "evoker", "evokers" }) :
         "The training hall of the evokers can be found to the west.",
      ({ "chamber", "path" }) :
         "The main chamber of research and the path out of the library "
         "can be found to the north.",
   ]) );
   SetItemAdjectives( ([
      "chamber" : ({ "main" }),
   ]) );
   SetSmell( ([
      "default" : "The smells of burnt wood and metals fill the air.",
   ]) );
   SetListen( ([
      "default" : "The area is oddly quiet and subdued.",
   ]) );
   SetTouch( ([
      "default" : "The air fairly crackles with energy.",
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:48:31 1999. */
