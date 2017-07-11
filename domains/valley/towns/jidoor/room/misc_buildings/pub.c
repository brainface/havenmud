//
// The Jidoor Pub
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Jidoor");
   SetClimate("indoors");
   SetAmbientLight(50);
   SetShort("Jidoor City Pub");
   SetLong("This small pub is almost completely empty. Many barstools "
           "are snuggled up to the counter waiting for someone to "
           "occupy them. There are a few tables in the middle of the "
           "room with chairs around to sit at. Many windows face into "
           "the streets of Jidoor showing people constantly going "
           "by.");
   SetItems( ([ 
      ({ "barstool", "barstools" }) : 
         "These barstools are covered with dust and dirt.",
      ({ "dust", "dirt", "speckles", "speckle" }) : 
         "This speckles of dust and dirt are covering virtually "
         "everything in the room.",
      ({ "people" }) : 
         "The people out on the street are scurrying in many different "
         "directions.",
      ({ "large counter", "counter" }) : 
         "This large counter stretches along one whole side of the pub.",
      ({ "dusty tables", "table", "tables" }) : 
         "These tables are covered with dust, as if they haven't been used "
         "in a very long time.",
      ({ "vacant chairs", "chair", "chairs" }) : 
         "These chairs vacantly sit at the tables.",
      ({ "window", "windows" }) : 
         "These windows plainly stare into the streets of Jidoor.",
      ({ "streets of jidoor", "street of jidoor", "streets", "street" }) : 
         "These streets outside from the pub are running deep through the "
         "city.",
   ]) );
   SetItemAdjectives( ([
      "counter" : ({ "large" }),
      "table" : ({ "dusty" }),
      "chair" : ({ "vacant" }),
   ]) );
   SetExits( ([ 
      "out" : JID_ROOM "/road1",
   ]) );
   SetSmell( ([ 
      "default" : "The smell of dust wafts through the air.",
   ]) );
   SetInventory( ([ 
      JID_NPC "/waplar" : 1,
   ]) );
}
