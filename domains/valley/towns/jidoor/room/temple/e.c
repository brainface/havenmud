/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: e.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: Outside the Tower of Air in the Magildan Temple
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();

  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");

  SetShort("outside of the Tower of Air in the Magildan Temple");
  SetDayLong(
    "Sunlight warms the area with its cheery orange glow. "
    "Zaxan has formed the tower from ethereal mists. The mists are "
    "like clouds, shifting and moving from moment to moment, making "
    "the tower appear translucent and transient. It is hard to tell "
    "where its boundaries are, save for an stone archway that leads "
    "in. The power of Zaxan is manifest here, while the tower "
    "objectifies the beauty that is air.");

  SetNightLong(
    "Zaxan has formed the tower from ethereal mists that glow softly, "
    "lighting the night with an errie light. The mists are "
    "like clouds, shifting and moving from moment to moment, making "
    "the tower appear translucent and transient. It is hard to tell "
    "where its boundaries are, save for an stone archway that leads "
    "in. The power of Zaxan is manifest here, while the tower "
    "objectifies the beauty that is air.");

  SetItems( ([
    ({ "" }) : (: GetLong :),

    ({ "tower","tower of air" }) :
        "This is the Tower of Air inside the Magildan Temple "
        "and is tribute to Zaxan.",

    ({ "mist","mists" }) :
        "The mists that form the tower writhe like snakes, weaving to "
        "compose the rough outline of the tower.",

    ({"boundaries","boundary"}) :
       "The shifting mists make it hard to tell anything about the "
       "size or shape of the tower.",

    ({"archway"}) :
       "The archway leads into the tower.",
   ]) );

  SetItemAdjectives( ([
    "tower" : ({ "translucent","transient" }),
    "mist" : ({"eerie","glowing","shifting","moving","ethereal"}),
    "boundry" : ({"shifting","changing","moving"}),
    "archway" : ({"stone"}),
  ]) );

  SetExits( ([
      "northeast" : JID_ROOM "/temple/grove",
  ]) );

  SetEnters( ([
      "tower" : JID_ROOM "/temple/air_tower",
  ]) );

  SetListen( ([ "default" : "Nothing but the sounds of the wind pass "
                            "through the area.",
  ]) );

  SetSmell( ([ "default" : "The smell of the grass and flowers is "
                           "fresh and thick in the air." ] ));

}

