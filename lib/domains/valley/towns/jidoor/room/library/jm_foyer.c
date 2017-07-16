/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: jm_foyer.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Nov 1st, 1998
// Abstract: The foyer of the Jidoormage Hall.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetAmbientLight(60);
   SetProperty("no bump", 1);
   SetClimate("indoors");
   SetShort("The Jidoormage Foyer");
   SetLong("The Jidoormage public foyer is a fantastically well decorated "
           "an exquisite area.  A sofa against the wall sits so that one "
           "may look out the window and enjoy the view while waiting "
           "for an audience with a Jidoormage.  A metal spiral staircase "
           "leads back downstairs.");
   SetItems( ([
      ({ "foyer", "room", "hall" }) : 
         (: GetLong :),
      ({ "sofa" }) : "The sofa is comfortable and large enough to hold at "
           "least four people",
      ({ "window" }) : "The window overlooks the street outside the library.",
      ({"staircase"}) : "The staircase is small, but sturdy looking.",
   ]) );
   SetItemAdjectives( ([
      "foyer" : ({ "jidoormage","public" }),
      "staircase" : ({"spiral","metal"}),
   ]) );
   SetListen( ([ 
            "default" : "The sounds of outside are quietened by the building "
                   "but still echo into the hall."
           ]) );
   SetSmell( ([ 
            "default" : "The room smells fresh and new.  Only a faint smell "
                   "of old books filters into the room.",
          ]) );
   SetExits( ([ 
      "down" : JID_ROOM + "/library/lib_foyer",
   ]) );
   SetInventory( ([ 
   ]) );
   AddExit("east", JID_ROOM "/library/jm_boardroom", (: PreExit :));
}

int PreExit() {
   if( (this_player()->GetGuild() != "jidoormage") &&
       (!creatorp(this_player())) ) {
      message("system","%^BOLD%^YELLOW%^A magical aura refuses your entry.%^RESET%^",this_player());
      return 0;
   } else {
      message("system","%^BOLD%^%^MAGENTA%^You step through a magical aura.%^RESET%^",this_player());
      return 1;
   }

}
