/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: boardroom.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Feb 13th, 1999
// Abstract: Magildan Message Room
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Jidoor");
   SetClimate("indoors");
   SetProperties( ([ "no bump" : 1 ]) );
   SetProperties( ([ "no combat" : 1 ]) );
   SetProperties( ([ "no teleport" : 1 ]) );
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
   SetAmbientLight(45);
   SetShort("the message room of the Magildan faith");
   SetLong("This section of the tower is set out for Magildans to leave "
           "messages for each other on a bulletin board. The room itself "
           "is very plainly decorated. There is a small window overlooking "
           "the grove beneath the tower and a few couches for people to "
           "sit while they write their messages. A marble staircase "
           "spirals along the circular wall of the tower down into the main "
           "chamber of the church.");
   SetItems( ([
      ({ "tower","church","temple","room"}) : (: GetLong :),
      ({ "spiral staircase", "staircase" }) : 
         "The white marble staircase spirals around down the wall of the "
         "tower back to the temple of Zaxan Zimtafarous.",
      ({"window"}) : "The window overlooks the canopy of the grove beneath "
         "the tower in the center of the temple.",
      ({"grove","canopy","tree","trees"}) : "The grove is covered by a "
         "thick canopy of healthy tees.",
      ({"chamber"}) : "The main chamber of the church is just below the "
         "meeting hall.",   
      ({"couch","couches"}) : "The couches are plain looking and simply "
         "serve the purpose of having somewhere to sit.",
   ]) );
   SetItemAdjectives( ([
      "church" : ({ "magildan" }),
      "room" : ({ "message" }),
      "chamber" : ({"main"}),
      "trees" : ({ "healthy" }),
      "staircase" : ({ "spiral","marble","white" }),
   ]) );
   SetNewsgroups( ({ "religion.magildan" }) );
   SetInventory( ([ 
   ]) );
   SetExits( ([ 
      "down" : JID_ROOM "/temple/main_tower",
   ]) );
  SetListen( ([ "default" : "It is peacefully quiet here.",
  ]) );
  SetSmell( ([ "default" : "The smell of a thick incense penetrates the "
                  "room." ] ));
}
