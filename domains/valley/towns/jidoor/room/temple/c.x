/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: c.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: Outside the Tower of Earth in the Magildan Temple
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();

  SetTown("Jidoor");
  SetDomain("Valley");
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
  SetClimate("temperate");

  SetShort("outside of the Tower of Earth in the Magildan Temple");
  SetDayLong(
    "Sunlight warms the area with a cheery orange glow. "
    "The tower appears to have been ripped from the very earth itself; "
    "the walls are jagged and consist of clay, stone and roots. "
    "The clay has been baked solid by elemental fire, making it "
    "impenetrable. The presence of Zaxan Zimtafarous is strong here, while "
    "the majesty of the element of earth is overcoming.");
  SetNightLong(
    "Moonlight casts an eerie white glow on the area. "
    "The tower appears to have been ripped from the very earth itself; "
    "the walls are jagged and consist of clay, stone and roots. "
    "The clay has been baked solid by elemental fire, making it "
    "impenetrable. The presence of Zaxan is strong here, while "
    "the majesty of the element earth is overcoming.");

  SetItems( ([    

    ({ "tower","earth","element","tower of earth" }) : 
        "This is the Tower of Earth inside the Magildan Temple "
        "and is tribute to the Lord of Elemental Energies.",

    ({"wall","walls","clay","stone","root","roots"}) :
       "The walls appear to have been cut from existing earth in "
       "the area.  It has been fired by elemental flame, making it"
       "as solid as steel.",
    ]) );

  SetItemAdjectives( ([
    "tower" : ({ "ripped","earth" }),
    "walls" : ({"jagged","clay","baked","cut","fired"}),  
  ]) );

  SetExits( ([ 
      "southwest" : JID_ROOM "/temple/grove",
  ]) );

  SetEnters( ([ 
      "tower" : JID_ROOM "/temple/earth_tower",
  ]) );

  SetListen( ([ "default" : "Nothing but the sounds of the wind pass "
                            "through the area.",
  ]) );

  SetSmell( ([ "default" : "The smell of the grass and flowers is "
                           "fresh and thick in the air." ] ));
                           
  SetProperties ( (["no bump" : 1]) );
  SetProperties ( (["no combat" : 1]) );
  SetProperties ( (["no teleport" : 1]) );                         
}
