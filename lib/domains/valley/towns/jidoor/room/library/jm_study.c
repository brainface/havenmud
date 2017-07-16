/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: jm_study.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Nov 1st, 1998
// Abstract: The study of the Jidoormage Hall.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

void eventCoolFountain();
void eventCoolFountain2();

static void create() {
   room::create();
   SetAmbientLight(60);
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
   SetProperty("no teleport", 1);
   SetClimate("indoors");
   SetShort("The Jidoormage Study");
   SetLong("The Jidoormage Study is quiet and a solemn place to spend "
           "time practicing your arts. It is devoid of decorations or "
           "other things that might provide a distraction. The only "
           "thing of interest in the room is a beautiful fountain "
           "resting in the center of the room. An archway leads north "
           "into the boardroom.");
   SetItems( ([
      ({ "study", "room", "hall","jidoormage study" }) : 
         (: GetLong :),
      ({ "archway" }) : "The archway is large enough for one person to "
                        "pass through at a time and is not as beautiful "
                        "on this side as it is from the boardroom.",
   ]) );
   SetListen( ([ 
            "default" : "The rushing water of the fountain is the only "
                        "sound penetrating the silence of the room."
           ]) );
   SetSmell( ([ 
            "default" : "The room smells fresh and new.  Only a faint smell "
                   "of old books filters into the room.",
          ]) );
   SetInventory( ([ 
      JID_OBJ "/mage_fountain" : 1,
   ]) );

   SetExits( ([ 
       "north" : JID_ROOM "/library/jm_boardroom",
   ]) );
   call_out( (: eventCoolFountain :), 500 );
}

void eventCoolFountain() {
   message("other_action","%^GREEN%^The water in the fountain suddenly "
           "stops "
           "flowing, and begins to clump into floating bubbles of water. "
           "It looks as though gravity has lost all control over the "
           "water.%^RESET%^",this_object());
   call_out( (: eventCoolFountain2 :), 15);
   return;
}

void eventCoolFountain2() {
   message("other_action","%^GREEN%^As suddenly as it began, the mind "
           "boggling effect "
           "ends and the fountain returns to normal.%^RESET%^",this_object());
  return;
}
