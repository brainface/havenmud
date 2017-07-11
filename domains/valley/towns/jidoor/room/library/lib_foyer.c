/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lib_foyer.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 22nd, 1998
// Abstract: This is the foyer of the Great Library of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetAmbientLight(60);
   SetClimate("indoors");
   SetShort("the foyer of the Great Library of Jidoor");
   SetLong("The Great Library of Jidoor is a resource of knowledge of all "
              "its "
              "citizens. It is a beautiful building made from marble and "
              "various types of wood. There are couches, chairs and tables "
              "placed in various positions around the foyer. An archway "
              "along the east wall leads into another section of the "
              "library. A metal spiral staircase leads upstairs.");
   SetItems( ([
      ({ "building", "library","library of jidoor","foyer" }) : 
         (: GetLong :),
      ({ "chair","chairs","couch","couches","table","tables" }) : 
         "Comfortable looking couches and chairs are available for "
         "the patrons of the library to sit and read.  Most have tables "
         "of various sizes nearby.",
      ({"archway"}) : "An archway on the eastern wall leads into another "
         "section of the library.",
      ({"wall","eastern wall"}) : "The eastern wall contains a large "
         "archway.",
      ({ "floor","ceiling"}) : "The floor and ceiling are made entirely "
         "out of green marble that casts an eerie glow throughout the "
         "room.",
      ({"marble","wood","various types of wood"}) : "The building is made "
         "from exquisite materials and is completely awe inspiring to "
         "stand in. The marble stone is a dark green color and casts an "
         "eerie light throughout the library. The oak, pine and cedar wood "
         "that make up the majority of the structure look to be of the "
         "highest quality.",
      ({"staircase" }) : "The staircase is small, but sturdy looking.",
          ]) );
   SetItemAdjectives( ([
      "building" : ({ "beautiful" }),
      "library" : ({"beautiful","great" }),
      "staircase" : ({"small","spiral"}),
   ]) );
   SetExits( ([ 
      "out" : JID_ROOM "/road2",
      "east" : JID_ROOM "/library/lib_crossway",
      "up" : JID_ROOM "/library/jm_foyer",
   ]) );
  SetListen( ([ "default" : "The library is quiet except for the "
                "occasional sound from outside penetrating the silence "
                "of the library." ]) );
  SetSmell( ([ "default" : "The library smells fresh and new, but the "
                  "smell of old books is heavy in the air." ]) );
}
