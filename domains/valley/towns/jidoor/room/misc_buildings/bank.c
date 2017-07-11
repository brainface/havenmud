//
// The Jidoor Bank
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetProperties( ([ 
      "no bump" : 1,
   ]) );
   SetShort("the Jidoor Bank");
   SetClimate("indoors");
   SetAmbientLight(60);
   SetLong("This small building is made completely out of wood. A "
           "counter on the western side provides a spot for "
           "business to take place. On the northern side, there is "
           "a large, open doorway to the main street of the city.");
   SetItems( ([
      ({ "small building", "building" }) : 
         (: GetLong :),
      ({ "wooden counter", "counter" }) : 
         "This wooden counter provides a suitable spot to carry out "
         "business.",
      ({ "large doorway", "doorway" }) : 
         "This doorway in the northern wall opens up onto the main "
         "street of the city.",
      ({ "main street", "street of the city", "street" }) : 
         "Outside of this building, a small street twists through the city.",
      ({ "city" }) : 
         "The city sits outside this building very invitingly.",
   ]) );
   SetItemAdjectives( ([
      "building" : ({ "small", "wooden" }),
      "counter" : ({ "wooden" }),
      "doorway" : ({ "large", "open" }),
      "street of the city" : ({ "main" }),
   ]) );
   SetExits( ([ 
      "out" : JID_ROOM "/road7",
   ]) );
   SetInventory( ([ 
//      JID_NPC "/guard" : 1,
      JID_NPC "/purlad" : 1,
   ]) );
}
