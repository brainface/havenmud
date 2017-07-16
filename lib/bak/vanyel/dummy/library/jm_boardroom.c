/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: jm_boardroom.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Nov 1st, 1998
// Abstract: The guild hall boardroom of the Jidoormages
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetAmbientLight(60);
   SetProperty("no teleport", 1);
   SetClimate("indoors");
   SetShort("The Jidoormage Boardroom");
   SetLong("The Jidoormage hall opens into a beautiful circular room "
           "with a large oak roundtable surrounded by about twelves "
           "chairs. Off to the side, there is a message board, for the "
           "mages to leave important notes to each other.  The walls have "
           "bookcases adjoined to them, with literally thousands of books "
           "lining them. An archway in the southern wall leads into the "
           "study and another on the western wall leads into the entrance "
           "of the guildhall.");
   SetItems( ([
      ({ "boardroom", "jidoormage boardhall", "room", "hall" }) : 
         (: GetLong :),
      ({ "bookcases","books","bookcase","book" }) : "The bookcases are "
           "lined with thousands of books about all sorts of topics.",
      ({ "archway","archways" }) : "The two archways are magnificient "
           "creations.",
      ({ "wall","walls" }) : "The wall is circular and is lined with "
           "bookshelves",
      ({ "roundtable", "table","chairs","chair" }) : "The circular table "
           "is a wonderous creation of woodwork.  The chairs, equally "
           "beautiful look comfortable and stable.",
   ]) );
   SetItemAdjectives( ([
      "roundtable" : ({ "large", "oak" }),
   ]) );
   SetListen( ([ 
            "default" : "Few sounds penetrate the quietness of the room."
           ]) );
   SetSmell( ([ 
            "default" : "Although the room is new and clean, the smell of "
                  "the old books is evident.",
          ]) );
   SetInventory( ([ 
      JID_OBJ "/mage_board" : 1,
   ]) );
   SetExits( ([ 
      "west" : JID_ROOM "/library/jm_foyer",
      "south" : JID_ROOM "/library/jm_study",
   ]) );
}
