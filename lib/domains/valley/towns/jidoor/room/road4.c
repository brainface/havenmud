/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road4.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: January 16th, 1999
// Abstract: The 4th section of road in Jidoor.
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
   SetShort("Magildan Avenue East");
  SetDayLong("The avenue continues east and also heads west towards the "
             "city's center. An inn of some sort lies on the northern side "
             "of the avenue with an entrance visible from here and another "
             "further east. The city of Jidoor is "
             "surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly visible. "
             "Sunlight shines down upon the city everywhere.");
  SetNightLong("The avenue continues east and also heads west towards the "
             "city's center. An inn of some sort lies on the northern side "
             "of the avenue with an entrance visible from here and another "
             "further east. The city of Jidoor is "
             "surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly visible. "
             "Moonlight shines down upon the city illuminating everything "
             "in a hazy white glow.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", "avenue", 
         "magildan avenue", "magildan avenue east"}) : (: GetLong :),
      ({ "center","city's center" }) : "The city's center is not too far "
             "west of here.",
      ({ "inn" }) : "The inn to the north looks inviting and open.",
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
   ]) );
   SetExits( ([ 
      "west" : JID_ROOM "/twnsquare",
      "east" : JID_ROOM "/road5",
   ]) );
   SetEnters( ([ 
      "inn" : JID_ROOM "/misc_buildings/inn",
   ]) );
  SetListen( ([ 
      "default" : "The sounds of the city's square enter from the east.",
           ]) );
  SetSmell( ([ 
      "default" : "The clean air is quite refreshing." 
           ] ));
}
