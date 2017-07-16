/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: twnsquare.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: Nov 6th, 1998
// Abstract: Jidoor City Square
// Revision History: File originally created by Zaxan@haven, but recoded
//                   from scratch by Zaxan Zimtafarous@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

void eventCoolFountain();
void eventCoolFountain2();

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");
  SetShort("Jidoor's City Square");
  SetLong("The town square of Jidoor is perhaps the busiest spot in the "
           "city. A magnificient statue of a sprite is the center of "
           "attention, standing in the center of a beautiful fountain. The "
           "street branches off in the four cardinal directions providing "
           "access to the rest of the city. The city hall rests on the "
           "southwestern corner and can be entered from here.");
  SetItems( ([ 
      ({ "street", "road" }) : 
         "The street meets here to create a square.",
      ({ "city","spot"}) : (: GetLong :),
      ({ "hall" }) : "The city hall is directly southwest of the town's "
            "square and is accessible from here.",
      ({ "jets","jet","water" }) : "The clean water in the fountain is "
            "being jetted towards the statue, but doesn't actually "
            "hit it."
   ]) );
   SetItemAdjectives( ([
      "hall" : ({ "city" }),
   ]) );
  SetInventory( ([ 
      JID_NPC "/sentry" : 1,
      JID_OBJ "/fountain" : 1,
      JID_OBJ "/statue" : 1,
      JID_NPC "/controller" : 1,
   ]) );
  SetExits( ([ 
      "north" : JID_ROOM "/road8",
      "south" : JID_ROOM "/road3",
      "east" : JID_ROOM "/road4",
      "west" : JID_ROOM "/road6",
   ]) );
   SetEnters( ([ 
      "hall" : JID_ROOM "/cityhall/foyer",
   ]) );
  SetListen( ([ 
      "default" : "The sounds of the city are all around.",
           ]) );
  SetSmell( ([ 
      "default" : "The air smells fresh and clean." 
           ] ));
   call_out( (: eventCoolFountain :), 750 );
}

void eventCoolFountain() {
   message("other_action","%^BOLD%^CYAN%^The jets of water in the "
           "fountain suddenly shoot high into the air."
           "%^RESET%^",this_object());
   call_out( (: eventCoolFountain2 :), 2);
   return;
}

void eventCoolFountain2() {
   message("other_action","%^BOLD%^%^CYAN%^The water from the jets "
           "lands back in the fountain causing a light mist to spray "
           "the area.%^RESET%^",this_object());
   call_out( (: eventCoolFountain :), 750 );
   return;
}
