/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lib_sage.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 22nd, 1998
// Abstract: This is the sage's area of the Great Library of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetAmbientLight(60);
  SetClimate("indoors");
  SetShort("the languages section of the Great Library of Jidoor");
  SetLong("This section of the Great Library of Jidoor seems to be some "
           "sort of lecture type area. Rows of chairs are set facing a "
           "small podium near the southern wall.  More paintings line the "
           "walls along with more shelves of books. An archway along the "
           "northern wall leads into the crossway of the library.");
  SetItems( ([
      ({ "section", "building", "library", "library of jidoor" }) : 
         (: GetLong :),
      ({"paintings","painting"}) : "One could spend hours here enjoying "
         "wonderous paintings of the library.  Several are abstract "
         "paintings and others depict landscapes, and still others are "
         "portraits of people.",
      ({ "floor","ceiling"}) : "The floor and ceiling are made entirely "
         "out of green marble that casts an eerie glow throughout the "
         "room.",
      ({"wall","walls","southern wall", "northern wall"}) : "The walls "
         "are adorned with paintings with the exception for the northern "
         "wall "
         "which has a archway leading into the library's crossway. Near "
         "the southern wall a podium sits for someone to stand at and "
         "give lectures or speeches from.",
      ({"podium" }) : "The podium is used primarily for lectures.  It is "
          "small, but exquisite non-the-less.", 
      ({ "shelves","shelves of books","shelf"}) : 
          "The various shelves of the library contain hundreds if not "
          "thousands of books.",
      ({"books","book"}) : "Thousands of books line the shelves of the "
          "library.",
      ({"crossway" }) : "Going north would yield a better view.  It is "
          "barely visible through the archway in the northern wall.",
      ({ "rows of chairs", "chair","chairs"}) : "Set up in rows facing "
         "the podium, the "     
         "comfortable looking chairs are here for the patrons of the "
         "the library to sit and listen to the person at the podium.",
      ({"archway","northern archway"}) : "An archway on the northern wall "
          "leads into the crossway of the library.",
          ]) );
  SetItemAdjectives( ([
       "building" : ({ "beautiful" }),
       "library" : ({"beautiful","great" }),
   ]) );
  SetExits( ([ 
      "north" : JID_ROOM "/library/lib_crossway",
   ]) );
  SetInventory( ([
    JID_NPC "/lorka" : 1,
    JID_NPC "/nylrius" : 1,
  ]) );
  SetSmell( ([ "default" : "The library smells fresh and new, but the "
                  "smell of old books is heavy in the air." ]) );
}
