//
// The Jidoor Healing Shop
// Created by Zaxan@Haven
//
 
#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Jidoor");
   SetClimate("indoors");
   SetAmbientLight(60);
   SetShort("The Jidoor Healing Shop");
   SetLong("This is the Jidoor Healing Shop. Many wounded people "
           "come here to get healed by the local healer for a small "
           "price. There are many tools and gadgets sitting on a small "
           "table in the corner of the room. A sign is hanging on "
           "the wall here with all of the current prices for the "
           "healing services.");
   SetExits( ([ 
      "out" : JID_ROOM "/glade",
   ]) );
   SetItems( ([ 
      ({ "tools", "gadgets", "tool", "gadget" }) : 
         "These tools and gadgets sitting on the table are "
         "used to the healer to carry out his job.",
      ({ "table" }) : 
         "This is a small wooden table in the corner of the room with "
         "many tools and gadgets on it.",
      ({ "sign" }) : 
         "This small sign has the current prices for the healing services "
         "of this shop on it.",
   ]) );
  SetRead("sign", "The sign has been scribbled on and is unreadable.");
   SetInventory( ([ 
      JID_NPC "/zurlock" : 1,
   ]) );
}
