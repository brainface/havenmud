/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lib_crossway.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 22nd, 1998
// Abstract: This is the crossway of the Great Library of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetAmbientLight(60);
   SetClimate("indoors");
   SetShort("the crossway of the Great Library of Jidoor");
   SetLong("The crossway of the Great Library of Jidoor is as beautiful "
           "as the rest of the building and is modestly decorated with "
           "paintings. Couches, chairs and tables are also placed randomly "
           "about the room to allow the patrons of the library to spend "
           "time studying and reading. Three archways, lead into different "
           "areas of the library. Shelves of books line the walls as well "
           "as standing shelves in the center of the room.");
   SetItems( ([
      ({ "building", "library", "library of jidoor","crossway","room" }) : 
         (: GetLong :),
      ({"paintings","painting"}) : "One could spend hours here enjoying "
         "wonderous paintings of the library.  Several are abstract "
         "paintings and others depict landscapes, and still others are "
         "portraits of people.",
      ({ "shelves","shelves of books"}) : 
          "The various shelves of the library contain hundreds if not "
          "thousands of books.",
      ({"books","book"}) : "Thousands of books line the shelves of the "
          "library.",
      ({ "chair","chairs","couch","couches","table","tables" }) : 
         "Comfortable looking couches and chairs are available for "
         "the patrons of the library to sit and read.  Most have tables "
         "of various sizes nearby.",
      ({ "floor","ceiling"}) : "The floor and ceiling are made entirely "
         "out of green marble that casts an eerie glow throughout the "
         "room.",
      ({ "walls","wall" }) : "The walls are covered with shelves.",
      ({"archway","western archway"}) : "An archway on the western wall "
          "leads into the foyer of the library.",
      ({"archway","eastern archway"}) : "An archway on the eastern wall "
          "leads into another area of the library.",
      ({"archway","southern archway"}) : "An archway on the southern wall "
          "leads into another area of the library.",
          ]) );
   SetItemAdjectives( ([
      "building" : ({ "beautiful" }),
      "shelves" : ({"standing"}),
      "library" : ({"beautiful","great" }),
   ]) );
   SetInventory( ([ 
      "/domains/southern_coast/towns/haven/obj/spell_board" : 1,
   ]) );

   SetExits( ([ 
      "east" : JID_ROOM "/library/tower",
      "west" : JID_ROOM "/library/lib_foyer",
      "south" : JID_ROOM "/library/lib_sage",
   ]) );
  SetListen( ([ "default" : "The library is quiet except for the "
                  "occasional sound of someone else working in the "
                  "library." ]) );
  SetSmell( ([ "default" : "The library smells fresh and new, but the "
                  "smell of old books is heavy in the air." ]) );

}
