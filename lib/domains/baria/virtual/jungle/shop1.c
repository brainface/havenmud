/*  Portia  Ruins  10-10-98
   A shop to be entered from "6,-5"
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a small shop");
  SetClimate("tropical");
  SetExits( ([
        "out" : RUINS_ROOMS + "7,-4",
         ]) );
  SetListen( ([
        "default" : "The area is deathly quiet.",
         ]) );
  SetSmell( ([
        "default" : "The area smells very earthen.",
          ]) );
  SetInventory( ([
/*
        RUINS_NPC + "lizardman4" : 1
*/
           ]) );
  SetLong("Except for the lack of a ceiling, this building seems to "
          "be in perfect structural condition. The inside of the stone "
          "walls are blackened apparently from a hot fire long ago. "
          "Nothing in the building survived the apparent fire, so "
          "there is not much to look at.");
  SetItems( ([
        "building" : (:GetLong:),
        ({"walls", "inside", "wall"}) :  "The walls have been blackened "
                                      "by fire.",
          ]) );
  SetItemAdjectives( ([
        "walls" : "stone",
         ]) );
  }
