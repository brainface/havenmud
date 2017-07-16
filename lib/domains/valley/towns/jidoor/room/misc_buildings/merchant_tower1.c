/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: merchant_tower1.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Feb 4th, 1999
// Abstract: This is the merchant's tower in Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetProperties( ([
       "metal repair" : 1,
       "natural repair" : 1,
       "wood repair" : 1,
       "leather repair" : 1,
       "textile repair" : 1,
       "mithral repair" : 1,
      ]) );
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("the entranceway of a small tower");
  SetLong("This floor of the tower has obviously been set up as a "
          "small forge and workshop.  The area used for working with "
          "metals is considerably smaller than the area designed to "
          "to allow work on textiles and other materials. A "
          "doorway leads out to the street. A staircase leads "
          "up.");
  SetItems( ([ 
     ({"entranceway","floor","tower","forge","shop",
       "workshop"}) : (: GetLong :),
     ({ "doorway","door" }) : "The doorway simply leads out to the "
          "street and is not of any interest.",
     ({ "staircase" }) : "The small spiral staircase leads up to the "
         "next floor of the tower.",
  ]) );
  SetInventory( ([ 
        JID_NPC "/lyuin" : 1
              ]) );
  SetExits( ([ 
     "up" : JID_ROOM "/misc_buildings/merchant_tower2",
     "out" : JID_ROOM "/road15",
  ]) );
  SetListen( ([ 
      "default" : "The crackling sounds of the forge's fire are continous.",
           ]) );
  SetSmell( ([ 
      "default" : "The room smells like burning wood." 
           ] ));
}
