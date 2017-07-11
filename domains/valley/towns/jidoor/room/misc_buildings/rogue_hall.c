/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: rogue_hall.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Feb 4th, 1999
// Abstract: This is rogue's gathering place in Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("the Hall of Rogues");
  SetLong("The Hall of Rogues is a gathering place for mages of Jidoor "
          "who have turned to the trade of the rogue as a secondary "
          "profession. It is relatively clean, but decorated only with "
          "a few chairs and tables. A doorway leads out to the street.");
  SetItems( ([ 
     ({ "doorway","door" }) : "The doorway simply leads out to the "
          "street and is not of any interest.",
     ({ "chair","table", "chairs", "tables","chairs and tables" }) : 
         "The various tables and chairs of the area are for the patrons "
         "of the hall to sit and discuss the finer points of their "
         "trade.",
  ]) );
  SetInventory( ([ 
      JID_NPC "/jylrilin" : 1,
      JID_NPC "/volric" : 1,
              ]) );
  SetExits( ([ 
     "out" : JID_ROOM "/road16",
  ]) );
  SetListen( ([ 
      "default" : "It is relatively quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "There is a slight odor of ale here." 
           ] ));
}
