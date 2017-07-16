// Title: Durgoroth Town
// File: cave07.c
// Author: Arika@Haven
// Date: Jan. 1999
//
//
// Revision History: 
//


#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
     room::create();
     SetShort("a combat room deep in the cave");
     SetLong("This room has been quickly cut out of the cave "
                  "system for the purpose of giving the daemons a "
                  "place to keep their fighting skills fine-tuned.  "
                  "There are several logs stick vertically out of the "
                  "floor and horizontally out of the walls.  There are "
                  "also several make-shift dummies piled in the corner "
                  "of the room. "
                  );
     SetObviousExits("south");
     SetClimate("indoors");
     SetDomain("FrostMarches");
     SetAmbientLight(25);
     SetItems( ([
          ({"room","chamber","cave"}) : (: GetLong :),
          ({"several logs", "vertical logs","horizontal logs",
          "logs","log"}) : "The logs have been hacked and shredded "
               "quite a bit.  The markings look like they were made "
               "by sharp weapons or claws.",
          ({"dummies","several dummies","dummy"}) : "The dummies "
               "are simply thrown in the corner.  They are made of "
               "burlap and have been ripped to pieces. ",
          ({"corner"}) : "The corner of the cave is dark, but you "
                "can make out a pile of dummies lying there. "
          ]) );
     SetExits( ([
          "south"  : D_ROOM + "/cave06.c",
          ]) );
     SetInventory( ([
          D_NPC + "/valkyr" : 1,
          ]) );
     }
