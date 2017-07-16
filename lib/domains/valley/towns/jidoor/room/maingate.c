/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: maingate.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: December 11th, 1998
// Abstract: Main Gate to the City of Jidoor
// Revision History: Originaly Created by Zaxan@Haven
//                   Recoded entirely by Zaxan Zimtafarous@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

#define VALLEY_EXIT "/domains/valley/virtual/valley/0,45"

int PreExit(string dir);

static void create() {
   room::create();
   SetAmbientLight(60);
   SetTown("Jidoor");
   SetDomain("Valley");
   SetClimate("temperate");
   SetShort("The main gate of Jidoor");
   SetDayLong("The main gate Jidoor is a large golden colored gate filled "
           "with sparkling rupies. The gate is more for adornment than "
           "anything else and looks fragile but beautiful.  The road "
           "continues north into the city of magic known as Jidoor but "
           "also continues south further into the valley. In the daytime, "
           "sun glistening off the gate is a fantastic sight.");
   SetNightLong("The main gate Jidoor is a large golden colored gate "
           "filled "
           "with sparkling rupies. The gate is more for adornment than "
           "anything else and looks fragile but beautiful.  The road "
           "continues north into the city of magic known as Jidoor but "
           "also continues south further into the valley.  During the "
           "night, the rupies in the gate seem to reflect the light of "
           "city into the area, illuminating it with ease.");
   SetListen( ([ 
      "default" : "The area is quiet here but noises from the city filter "
                  "into the area.",
   ]) );
   SetSmell( ([ 
      "default" : "The crisp air of the city smells fresh and inviting.",
   ]) );
   SetItems( ([ 
      ({ "gate", "gates", "gate","city","city of magic",
         "jidoor","road","street" }) : (: GetLong :),
      ({"rupies"}): "The rupies in the gate are sparkling brightly.",
      ({"valley"}) : "Beyond the city gates lies the area of Kailie known "
         "only as 'the Valley.'",
   ]) );
   SetItemAdjectives( ([
      "gate" : ({ "main","golden","golden colored","fragile","beautiful"}),
   ]) );
   SetInventory( ([ 
      JID_NPC "/sentry" : 2,
   ]) );
   SetExits( ([ 
      "north" : JID_ROOM "/road1",
   ]) );
   AddExit("south",VALLEY_EXIT, (: PreExit :));
}

int PreExit(string dir) {
   if (this_player()->id("jid_protect") && this_player()->GetOwner() != "") { return 0; }
   else return 1;
}
