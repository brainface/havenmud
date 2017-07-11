/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: g.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: Outside the Tower of Water in the Magildan Temple
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();

  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");

  SetShort("outside of the Tower of Water in the Magildan Temple");
  SetDayLong(
    "The tower looms high, cresting the clouds above. Zaxan Zimtafarous has "
    "fashioned its exterior like a geyser, shooting up to the "
    "heavens like an arrow. Hot steam rolls of its walls, shrouding "
    "it from clear view. The power of Zaxan Zimtafarous is strong here, and "
    "the glory of the element water is wondrous indeed.");

  SetNightLong(
    "The tower looms high, cresting the clouds above.  Zaxan has "
    "fashioned its exterior like a geyser, shooting up to the "
    "heavens like an arrow.  It glows with a soft blue light, "
    "illuminating the immediate area.  Hot steam rolls of its walls, "
    "shouding it from clear view.  The power of Zaxan is strong here, "
    "and the glory of the element water is wondrous indeed.");

  SetItems( ([

    ({ "tower","water","area","element","tower of water" }) :
        "This is the Tower of Water inside the Magildan Temple "
        "and is tribute to the Lord of Elemental Energies.",

    ({ "cloud","clouds" }) :
        "The clouds block any view of the top of the tower.",

    ({ "water","geyser","wall","walls"}) :
        "The walls are boiling hot, letting off rolls of steam into "
        "the air.",

   ({ "steam","fog" }) :
        "The steam envelops the tower in a heavy fog.",
    ]) );

  SetItemAdjectives( ([
      "tower" : ({ "glowing","looming","cresting" }),
      "geyser" : ({"shooting","boiling"}),
      "steam" : ({"hot","rolls","of","heavy","enveloping"}),
  ]) );

  SetExits( ([
      "northwest" : JID_ROOM "/temple/grove",
  ]) );

  SetEnters( ([
      "tower" : JID_ROOM "/temple/water_tower",
  ]) );

  SetListen( ([ "default" : "Nothing but the sounds of the wind pass "
                            "through the area.",
  ]) );

  SetSmell( ([ "default" : "The smell of the grass and flowers is "
                           "fresh and thick in the air." ] ));
}

