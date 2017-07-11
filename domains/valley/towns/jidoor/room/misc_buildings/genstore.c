//
// The Jidoor General Store
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
   SetShort("The Jidoor General Store");
   SetLong("This small store looks perfect for dealing with "
           "customers. A display case on the west "
           "has different things that are for sale while a counter "
           "on the north provides a spot for the storekeeper to "
           "do work. A ladder on the east heads up through the ceiling "
           "into another room.");
   SetExits( ([ 
      "out" : JID_ROOM "/road6",
      "up" : JID_ROOM "/misc_buildings/gemshop",
   ]) );
   SetItems( ([ 
      ({ "counter" }) : 
         "This counter on the northern side of the store provides a spot to "
         "do business.",
      ({ "display case", "case" }) : 
         "This display case has many different items and foods "
         "in it with prices attatched to each thing.",
      ({ "ladder" }) : 
         "This ladder goes up into the ceiling.",
      ({ "ceiling" }) : 
         "A small ladder passes through this ceiling into another room.",
      ({ "room" }) : 
         "Another room sits above this store.",
   ]) );
   SetItemAdjectives( ([
      "case" : ({ "display" }),
   ]) );
   SetInventory( ([ 
      JID_NPC "/opewat" : 1,
   ]) );
}
