//
// The Haven Town Hall
// Filename: town_hall.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;
  
static void create() {
   room::create();
   SetShort("Haven Town Hall");
  SetLong("The town hall remains a large and powerful building. "
          "Although the Dragon and Scales are still prominently "
          "displayed, it seems that secular rule has been "
         "restored here in Haven Town.  Upstairs is the private "
          "residence of the Mayor and his wife, Astara.");
   SetItems( ([
      ({ "hall", "building", "camp" }) :
         (: GetLong :),
      ({ "table", "desk" }) : 
         "This is a large oaken table, which serves as a desk.",
      ({ "symbol", "dragon", "scale", "scales" }) : 
         "This is the Dragon and Scales symbol of the Kylin faith.",
      ({ "residence" }) :
         "The residence of the mayor of Haven Town can be "
         "found upstairs.",
      ({ "banner" }) :
         "This banner is emblazened with the symbol of Kylin.",
   ]) );
   SetItemAdjectives( ([
      "hall" : ({ "haven", "town", "powerful", "base" }),
      "table" : ({ "large", "oak", "oaken" }),
      "symbol" : ({ "kylin" }),
   ]) );
   SetExits( ([
      "out" : "../holy_path/hp5",
      "up" : "res",
   ]) );
   SetClimate("indoors");
   SetAmbientLight(50);
   SetNewsgroups( ({ "town.haven" }) );
   SetInventory( ([
      H_NPC + "annax" : 1,
      H_OBJ + "poster" : 1,
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:20:24 1999. */
