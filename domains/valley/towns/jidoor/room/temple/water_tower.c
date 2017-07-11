/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: water_tower.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: inside the Tower of Water in the Magildan Temple
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"
inherit LIB_ROOM;

static void create()  {
    room::create();

  SetTown ("Jidoor");
  SetDomain ("Valley");
  SetClimate ("indoors");
  SetAmbientLight (40);

  SetShort ("the Tower of Water in the Magildan Temple");
  SetLong (
    "The circular tower glows a soft blue, shedding light on the "
    "beauty that is water.  A continuous waterfall pours out from "
    "the ceiling and running down to the floor, where it myteriously "
    "vanishes.  The floor is a smooth sheet of ice, in the center "
    "of which lies an alter of pure dewdrops.  The symbol of water "
    "is indented into the front of the altar.  A magical portal lies "
    "directly behind the altar, while a stone archway leads back to "
    "the grove.");

  SetItems ( ([

    ({"tower","water"}) :
       "This tower is a tribute to the element water and the greater "
       "glory of Zaxan.",

    ({"waterfall","ceiling"}) :
       "The waterfall runs the circumfrence of the ceiling, pouring "
       "down in a rapid current to the floor below.",

    ({"ice","floor"}) :
       "Magically, the ice provides the same friction as stone or "
       "wood.  In the center lies the altar dedicated to water.",

    ({"altar","dewdrop","dewdrops"}) :
       "The dewdrops have coalesced into the form of an altar, "
       "sacred to the Lord of Elememtal Energies.",

    ({"symbol","element","elements"}) :
       "The symbol of water, one of the four pure elements.",

    ({"portal","plane"}) :
       "By the images projected from the portal it appears to lead to "
       "another plane of existence.",

    ({"archway","grove"}) :
       "The stone archway projects the image of the grove of the "
       "Magildan Temple.",
    ]) );

  SetItemAdjectives( ([
    "tower" : ({"circular","lit","glowing"}),
    "waterfall" : ({"flowing","rapid","continuous","pouring"}),
    "ice" : ({"sheet","of","magical","smooth"}),
    "altar" : ({"dewdrop","pure"}),
    "symbol" : ({"of","water","indented"}),
    "portal" : ({"magical","of","existence"}),
    "archway" : ({"stone"}),
    ]) );

  SetInventory ( ([
    JID_NPC + "/water_elem" : 2,
    ] ) );

  SetSmell ( ([
    "default" : "The room has the scent of an ocean breeze."]) );

  SetListen ( ([
    "default" : "The sounds of rushing water and crashing waves "
                "resound through the tower."]) );

  SetEnters ( ([
    "portal" : JID_ROOM + "/temple/greathall",
    ]) );

  SetExits ( ([
    "out" : JID_ROOM + "/temple/grove",
    ]) );

}

