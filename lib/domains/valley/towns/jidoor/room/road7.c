/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road7.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: December 16th, 1998
// Abstract: The 7th section of road in Jidoor
// Revision History: Originally coded by Zaxan@Haven.  
//                   Recoded entirely by Zaxan Zimtafarous@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

void eventSweeperCantrip();
void eventDestroyGarbage();

static void create() {
   room::create();
   SetTown("Jidoor");
   SetDomain("Valley");
   SetClimate("temperate");
   SetShort("Magildan Avenue West");
   SetDayLong("The avenue here continues to the west into a bazaar of some "
             "sort. Back to the east it heads further back into the "
             "city. Garbage from careless and thoughtless people has been "
             "thrown along the sides of the road here, but it is "
             "obviously quite worse to the west. A stone building on the "
             "southern side of the street is quite obviously the city's "
             "bank. The sunlight is illuminating the area with ease and "
             "in the city of Jidoor itself, it is quite easy to see that "
             "the city is surrounded to the east, west and north by the "
             "Crystal Reaches as the peaks of the mountains are plainly "
             "visible and glowing in the daytime light.");
   SetNightLong("The avenue here continues to the west into a bazaar of "
             "some sort. Back to the east it heads further back into the "
             "city. Garbage from careless and thoughtless people has been "
             "thrown along the sides of the road here, but it is "
             "obviously quite worse to the west. A stone building on the "
             "southern side of the street is quite obviously the city's "
             "bank. The moonlight is illuminating the area with ease and "
             "in the city of Jidoor itself, it is quite easy to see that "
             "the city is surrounded to the east, west and north by the "
             "Crystal Reaches as the peaks of the mountains are plainly "
             "visible and glowing in the moonlight.");
   SetItems( ([ 
     ({"bazaar"}) : "The bazaar to the east seems to be an area of much "
             "excitement people are constantly walking to and from it.", 
     ({"garbage"}) : "The garbage on the streets in obviously from the "
            "visitors to the bazaar.  It is not ridiculous here like it "
            "is in the actual bazaar, but it is still an eyesore.",
     ({ "street", "jidoor", "city", "road", "avenue", 
         "magildan avenue", "magildan avenue west"}) : (: GetLong :),
      ({ "bank", "building" }) : 
         "This small bank sits on the southern side of the road and is "
         "well designed as most sprite architecture is.",
      ({"architecture"}) : "The architecture of the bank is standard for "
         "sprite work.  It is quite obvious the building will stand for "
         "a long time.",
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
   ]) );
   SetItemAdjectives( ([
      "bank" : ({ "small","stone" }),
      "architecture" : ({ "sprite" }),
   ]) );
   SetExits( ([ 
      "east" : JID_ROOM "/road6",
      "west" : "/domains/valley/areas/bazaar/room/entrance",

   ]) );
   SetEnters( ([ 
      "bank" : JID_ROOM "/misc_buildings/bank",
   ]) );
  SetInventory( ([ 
      JID_NPC "/mchild" : 1,
      JID_NPC "/fchild" : 1,
      JID_NPC "/sweeper" : 1,
   ]) );
  SetListen( ([ 
      "default" : "A great deal of noise filters in from "
           "the bazaar to the west.",
           ]) );
  SetSmell( ([ 
      "default" : "The air smells fresh and clean." 
           ] ));
   call_out( (: eventSweeperCantrip :), 250);
}

void eventSweeperCantrip() {
   if(present("navan")) {
      message("other_action","Navan closes his eyes and begins "
              "%^BLUE%^BOLD%^uttering an incantation%^RESET%^.",this_object());
      call_out( (: eventDestroyGarbage :), 5);
   }
   return;
}

void eventDestroyGarbage() {
   if(present("navan")) {
      message("other_action","Navan's magical powers quickly disintegrate "
              "a nearby piece of garbage.",this_object());
      call_out( (: eventSweeperCantrip() :), 250);
   }
   return;
}
