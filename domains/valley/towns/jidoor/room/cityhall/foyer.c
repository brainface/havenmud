/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: foyer.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: December 4th, 1998
// Abstract: City Hall Foyer
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

int PreExit();

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("The foyer of Jidoor City Hall");
  SetDayLong("The fantastic architecture of the city hall here in "
          "Jidoor is awe inspiring, like most of the city's "
          "buildings. Various statues and paintings are also prevalent "
          "throughout the room. There is a grand staircase leading "
          "upstairs "
          "as well downstairs. Sunlight is pouring through the "
          "window overlooking the town square of Jidoor.");
  SetNightLong("The fantastic architecture of the city hall here in "
          "Jidoor is awe inspiring, like most of the city's "
          "buildings. Various statues and paintings are also prevalent "
          "throughout the room. There is a grand staircase leading "
          "upstairs "
          "as well downstairs. The room is lit up at night by "
          "globes hanging from the ceiling.");
  SetItems( ([ 
      ({ "city hall","hall","architecture" }) : (: GetLong :),
      ({ "grand staircase", "staircase" }) : 
           "The staircase is made from a red colored marble.",
      ({ "painting","paintings" }) : "Some of the paintings are "
          "portraits of various people and others paintings of "
          "buildings.",
      ({ "statue","statues"}) : "The statues are made from various "
          "materials and are fantastic works of art.  Some are "
          "recognizable as citizens of the great city of Jidoor and "
          "and others are totally unrecognizable.",
      ({ "window" }) : "The window overlooks the town square.",
      ({ "globes","globe" }) : 
           "Hanging globes are the primary source of lighting at night.",
          ]) );
  SetInventory( ([ 
      JID_OBJ "/wanted_poster" : 1,
      JID_NPC "/eralyon" : 1,
  ]) );
  SetExits( ([ 
     "out" : JID_ROOM "/twnsquare",
     "down" : JID_ROOM "/cityhall/mayor_office",
  ]) );
  SetListen( ([ "default" : "Sounds from outside are easily "
               "penetrating the relative quiet of the hall."
            ]) );
  SetSmell( ([ "default" : "The air in the room smells crisp and "
               "pleasant."
          ] ));
  AddExit("up", JID_ROOM "/cityhall/citizens_room", (: PreExit :));
}

int PreExit() {
   if( (this_player()->GetTown() != "Jidoor") &&
       (!creatorp(this_player())) ) {
      message("system","%^BOLD%^MAGENTA%^A magical aura refuses your "
                "entry.%^RESET%^",this_player());
      return 0;
   } else {
      message("system","%^BOLD%^MAGENTA%^You pass through a magical "
                "aura.%^RESET%^",this_player());
      return 1;
   }
}
