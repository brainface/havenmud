/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: tower.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 23rd, 1998
// Abstract: This is the lowest section of the tower of the Great Library 
//           of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetAmbientLight(60);
   SetClimate("indoors");
   SetShort("the base of the tower in the Great Library of Jidoor");
   SetLong("The library comes to it's most unique feature as you enter "
           "the base of a tower.  The western wall holds an archway that "
           "leads into the main section of the library and a large marble "
           "staircase leads up into the tower and down into the cellar of "
           "of the library.  The craftsmanship of this section of the "
           "library is exquisite and entirely awe inspiring.  Paintings "
           "continue to decorate the library.");
   SetItems( ([
      ({ "building", "library", "library of jidoor","tower",
         "base of the tower" }) : 
         (: GetLong :),
      ({ "wall","walls"}) : "The walls of the tower are circular.",
      ({"paintings","painting"}) : "One could spend hours here enjoying "
         "wonderous paintings of the library.  Several are abstract "
         "paintings and others depict landscapes, and still others are "
         "portraits of people.",
      ({"archway","western archway"}) : "An archway on the western wall "
          "leads into the crossway of the library.",
      ({"staircase","stairs"}) : "The staircase is literally huge and "
          "reflects the light in the room, casting an eerie but pleasant "
          "radiance.  It leads up into the tower as well down into the "
          "cellar of the library.",
      ({"cellar"}) : "The cellar is down from here if you'd like a better "
             "look.",
          ]) );
   SetItemAdjectives( ([
      "building" : ({ "beautiful" }),
      "library" : ({"beautiful","great" }),
      "staircase" : ({"large","marble"}),
   ]) );
   SetExits( ([ 
      "west" : JID_ROOM "/library/lib_crossway",
      "down" : JID_ROOM "/library/cellar",
      "up" : JID_ROOM "/library/evoker",
   ]) );
  SetListen( ([ "default" : "The library is quiet except for the "
                  "occasional sound of someone else working in the "
                  "library." ]) );
  SetSmell( ([ "default" : "The library smells fresh and new, but the "
                  "smell of old books is heavy in the air." ]) );
}
