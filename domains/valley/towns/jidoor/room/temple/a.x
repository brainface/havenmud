/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: a.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: Outside the Tower of Fire in the Magildan Temple
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
  SetShort("outside of the Tower of Fire in the Magildan Temple");

  SetDayLong(
    "Sunlight casts a cheery orange glow on the area. "
    "The Tower of Fire looms high, breaking through the cloud "
    "cover. A mightly pillar of stone, its walls are engulfed"
    "in mystical flame.  The flames lick at the walls, yet do "
    "no damage to the structure. The power of Zaxan Zimtafarous radiates "
    "from the tower, while the magesty of the element is "
    "breathtaking in and of itself.");

  SetNightLong(
    "The Tower of Fire looms high, breaking through the cloud "
    "cover. A mighty pillar of stone, its walls are engulfed"
    "with flame, lighting the immediate area like it were day. "
    "The flames lick at the walls, yet do no damage to the "
    "structure. The power of the Lord of Elemental Energies radiates "
    "from the tower, while the majesty of the element is "
    "breathtaking in and of itself.");

  SetItems( ([ 
    ({ "pillar","element" }) : (: GetLong :),
 
    ({ "tower","structure","tower of fire" }) : 
        "This is the Tower of Fire inside the Magildan Temple "
        "and is tribute to Zaxan.",
    
    ({ "cloud","clouds" }) :
        "The tower pierces the clouds like a fiery lance.",

    ({ "wall","walls" }) :
        "The walls are built of stone that are magically protected "
        "from the destructive flames.",

    ({ "flame","flames","pattern" }) :
        "The flames dance across the stone pillar.  Their pattern "
        "is almost hypnotic.",
    ]) );

  SetItemAdjectives( ([
      "tower" : ({ "looming","tall","high" }),
      "pillar" : ({"mighty","of","stone"}),
      "wall" : ({ "engulfed","with","flame","stone","magical" }),
      "flame" : ({"destructive","dancing","hypnotic","licking" }),
      ]) );

  SetExits( ([ 
      "southeast" : JID_ROOM + "/temple/grove",
  ]) );

  SetEnters( ([ 
      "tower" : JID_ROOM + "/temple/fire_tower",
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
