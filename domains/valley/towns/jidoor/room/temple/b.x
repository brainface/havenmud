/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: b.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Unknown
// Abstract: Outside the Main Tower in the Magildan Temple
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");
  SetProperty("no magic", 1);
  SetProperty("no attack", 1);
  SetShort("outside of the main tower in the Magildan Temple");
  SetDayLong("The main tower of the Magildan Temple is huge and ominous. "
             "Constructed out of stone, it rises high into the sky and "
             "dwarves any other building in Jidoor. The tower is "
             "illuminated with light from the sun.");
  SetNightLong("The main tower of the Magildan Temple is huge and ominous. "
             "Constructed out of stone, it rises high into the sky and "
             "dwarves any other building in Jidoor. The tower is "
             "illuminated by moonlight.");
  SetItems( ([ 
    ({ "tower" }) : (: GetLong :),
  ]) );
  SetItemAdjectives( ([
      "tower" : ({ "main" }),
  ]) );
  SetExits( ([ 
      "south" : JID_ROOM "/temple/grove",
  ]) );
  SetEnters( ([ 
      "tower" : JID_ROOM "/temple/main_tower",
  ]) );
  SetListen( ([ "default" : "Nothing but the sounds of the wind pass "
                            "through the area.",
  ]) );
  SetSmell( ([ "default" : "The smell of the grass and flowers is "
                           "fresh and thick in the air." ] ));
}
