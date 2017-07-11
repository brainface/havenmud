/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: f.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Feb 12, 1999
// Abstract:
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetTown("Jidoor");	
   SetDomain("Valley");
   SetClimate("temperate");
  SetProperty("no magic", 1);
  SetProperty("no attack", 1);
   SetProperties( ([ "no bump" : 1, ]) );
   SetShort("the entrance to the Temple of the Magildan");
   SetDayLong("The Temple's entrance is a grassy area with a small path "
              "running into a grove north of here. An archway to the south "
             "allows access back to the city. The area is filled with the "
             "feeling of peace and tranquility. The sunlight is beaming "
             "on the area as though it shines directly upon the temple.");
   SetNightLong("The Temple's entrance is a grassy area with a small path "
                "running into the grove north of here. An archway to the south "
                "allows access back to the city. The area is filled with the "
             "feeling of peace and tranquility. The moon's light is "
             "beaming on the area as though it shines directly upon the "
             "temple.");
   SetExits( ([ 
      "south" : JID_ROOM "/road20",
   ]) );
   AddExit("north", JID_ROOM "/temple/grove" , (: PreExit :) );
   SetInventory( ([
      JID_NPC "/guard" : 2,
     JID_NPC + "/laeryn" : 1,     
   ]) );
   SetItems( ([
      ({ "entrance","temple","temple of magildan","area" }) : (: GetLong :),
      ({"archway"}) : "The archway is a beatifully crafted stone arch that "
           "allows access to the city south of here.",
      ({"path"}) : "The path leads north into the grove and south through "
           "the archway and back to the city.",
   ]) );
   SetItemAdjectives( ([
      "area" : ({ "grassy" }),
   ]) );
}

int PreExit() {
   if( (this_player()->GetReligion() == "Magildan") ||
       (immortalp(this_player())) ) {
   message("my_action","%^MAGENTA%^BOLD%^The trees seem to "
      "open wider to allow you easier access to the "
      "grove.%^RESET%^",this_player());
      return 1;
   }
   message("my_action","%^MAGENTA%^BOLD%^The trees seem to "
      "twist to bar every attempt you make to enter the "
      "grove.%^RESET%^",this_player());
   return 0;
}
