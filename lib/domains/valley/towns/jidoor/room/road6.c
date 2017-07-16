/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road6.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: December 30th, 1998
// Abstract: The 6th section of road in Jidoor.
// Revision History: Originally coded by Zaxan@Haven.  
//                   Recoded entirely by Zaxan Zimtafarous@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Jidoor");
   SetDomain("Valley");
   SetClimate("temperate");
   SetShort("Magildan Avenue West");
   SetDayLong("The avenue here continues to the west here and heads "
             "east back into the town square.  The city hall is set on "
             "the south side of the street while on the north a two "
             "story building rests.  Further to the west you can make "
             "out the "
             "city's bank.  Beyond the rooftops, the mountains of the "
             "Crystal Reaches are glistening in the sunlight.");
   SetNightLong("The avenue here continues to the west here and heads "
             "east back into the town square.  The city hall is set on "
             "the south side of the street while on the north a two "
             "story building rests.  Further to the west you can make "
             "out the "
             "city's bank.  Beyond the rooftops, the mountains of the "
             "Crystal Reaches are glistening in the moonlight.");
   SetItems( ([ 
     ({ "street", "jidoor", "city", "road", "avenue", 
         "magildan avenue", "magildan avenue west"}) : (: GetLong :),
     ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
     ({"store", "building"}) : "The two story stone and wooden building "
           "is a store of some sort.",
     ({"hall"}) : "The city hall rests on the southern side "
           "of the street but is not accessible from here.",
     ({"bank"}) : "The city's bank is further up the street "
           "to the west.",
     ({ "square" }) : "The town square of Jidoor is just east of here.",
   ]) );
   SetItemAdjectives( ([
      "store" : ({ "two story" }),
      "hall" : ({ "city" }),
      "bank" : ({ "city's" }),
      "square" : ({"town","city"}),
   ]) );
   SetExits( ([ 
      "east" : JID_ROOM "/twnsquare",
      "west" : "road7",
   ]) );
   SetEnters( ([ 
      "store" : JID_ROOM "/misc_buildings/genstore",
   ]) );
  SetListen( ([ 
      "default" : "The sounds of the city are all around.",
           ]) );
  SetSmell( ([ 
      "default" : "The air smells fresh and clean." 
           ] ));
}
