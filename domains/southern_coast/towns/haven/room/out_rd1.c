//
// Filename: out_rd1.c
// Near the Haven Town Gate
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "haven.h"

#define HAVEN 1

inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetShort("Near the main gate to Haven Town");
   SetDayLong("This small cobblestone road is right by "
              "the main gate of Haven Town, the largest "
              "town in the world. The main gate of Haven Town can "
              "be seen to the east. There are many people passing "
              "in and out of the gate in an effort to get work "
              "done.");
   SetNightLong("This small cobblestone road is right by "
                "the main gate of Haven Town, the largest "
                "in the world. The main gate of Haven Town can "
                "be seen to the east, with the town lights sparkling "
                "in the twilight. There are a few people passing "
                "in and out of the gate.");
   SetItems( ([
      ({ "road", "cobblestone road" }) : 
         "This small road is made out of nicely laid cobblestones.",
      ({ "town" }) : 
         "To the east, Haven Town can be seen.",
      ({ "gate" }) : 
         "This large gate to the east enters into Haven Town.",
      ({ "civilization" }) :
         "Haven Town is the main civilization in this area and it is "
         "located to the east.",
      ({ "people" }) : 
         "People are passing in and out of the gate to work and to "
         "get to different places in Kailie.",
   ]) );
   SetItemAdjectives( ([
      "town" : ({ "haven", "large", "largest" }),
      "gate" : ({ "main" }),
   ]) );
   SetListen( ([ 
      "default" : "The sounds of civilization can be heard to the east.",
   ]) );
   SetExits( ([
      "west" : H_ROOM + "out_rd2",
   ]) );
   AddExit("east", H_ROOM "gate", (: PreExit :));
}

int PreExit() {
   if(HAVEN) {
      return 1;
   } else {
      message("system","The town gives off a warding "
              "aura which you cannot cross.",this_player());
      return 0;
   }
}


/* Approved by Duuktsaryth on Sun Apr 25 18:34:43 1999. */
