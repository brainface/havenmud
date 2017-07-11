/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road5.c
// Author: Derek Noble
// Immortal: zaxan@haven, dylanthalus@haven
// Creation Date: December 11th, 1998
// Abstract: This is part of the main street of Jidoor.
// Revision History: Originally Created by Zaxan@Haven
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
  SetDayLong("The avenue continues east and heads west towards "
             "the city's center. An inn of some sort lies on the "
             "northern side of the avenue with an entrance visible "
             "from here and another further west. On the southern "
             "side of the road, another building is visible, looking "
             "significantly more public then the other one. The city "
             "of Jidoor is surrounded to the east, west and north by "
             "the Crystal Reaches and the peaks of the mountains are "
             "plainly visible. Sunlight from above illuminates the "
             "street in a soft orange glow.");
  SetNightLong("The avenue continues east and heads west towards "
             "the city's center. An inn of some sort lies on the "
             "northern side of the avenue with an entrance visible "
             "from here and another further west. On the southern "
             "side of the road, another building is visible, looking "
             "significantly more public then the other one. The city "
             "of Jidoor is surrounded to the east, west and north by "
             "the Crystal Reaches and the peaks of the mountains are "
             "plainly visible.  Moonlight casts a hazy white glow on "
             "street.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", "avenue", 
         "magildan avenue", "magildan avenue east"}) : (: GetLong :),
      ({ "center","city's center" }) : "The city's center is not too far "
             "west of here.",
      ({ "inn" }) : "The inn to the north looks closed.",
      ({ "building","office" }) : "On closer inspection, the building to "
             "the south appears to be the local post office.",
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
   ]) );
  SetExits( ([ 
      "east" : JID_ROOM "/road11",
      "west" : JID_ROOM "/road4",
    ]) );
  SetEnters( ([ 
      "building" : JID_ROOM "/misc_buildings/postoffice",
       "inn" : JID_ROOM "/misc_buildings/player_inn",
   ]) );
  SetListen( ([ 
      "default" : "The sounds of the city are all around.",
           ]) );
  SetSmell( ([ 
      "default" : "The air smells fresh and clean." 
           ] ));
}
