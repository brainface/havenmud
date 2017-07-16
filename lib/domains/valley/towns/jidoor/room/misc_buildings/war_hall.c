/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: rogue_hall.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Feb 4th, 1999
// Abstract: This is warrior's gathering place in Jidoor.
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
  SetShort("the Hall of War");
  SetLong("The Hall of War is a gathering place for mages of Jidoor "
          "who have learned the arts of warcraft.  It is relatively clean, "
          "but decorated only with a few chairs and tables. A doorway "
          "leads out to the street.");
  SetItems( ([ 
     ({ "doorway","door" }) : "The doorway simply leads out to the "
          "street and is not of any interest.",
     ({ "chair","table", "chairs", "tables","chairs and tables" }) : 
         "The various tables and chairs of the area are for the patrons "
         "of the hall to sit and discuss the finer points of their "
         "trade.",
  ]) );
  SetInventory( ([ 
      //enchanter/cavalier mutli, not legal: JID_NPC "/larn" : 1,
      JID_NPC "/kothus" : 1,
      //fighter/enchant mutli, not legal: JID_NPC "/saolin" : 1,
      JID_NPC "/urala" : 1,
      JID_NPC "/t_warlord" : 1,
              ]) );
  SetExits( ([ 
     "out" : JID_ROOM "/road13",
  ]) );
  SetListen( ([ 
      "default" : "It is relatively quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "There is a slight odor of ale here." 
           ] ));
}

