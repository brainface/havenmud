/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: air_tower.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: inside the Tower of Air in the Magildan Temple
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"
inherit LIB_ROOM;

static void create()   {
    room::create();

  SetTown ("Jidoor");
  SetDomain ("Valley");
  SetClimate ("indoors");
  SetAmbientLight (40);

  SetShort ("the Tower of Air in the Magildan Temple");
  SetLong (
    "The ethereal mists from beyond have been moulded by Zaxan to form "
    "the Tower of Air. The tower seems translucent and transient; "
    "nothing seems to stay in existence for longer than a fleeting "
    "moment. The walls, floor and ceiling are like clouds of fog "
    "that forever shift and change. A large cloud in the center of "
    "the room has taken the form of an alter, the imprint of the "
    "symbol of air imprinted on its front. Directly behind the alter "
    "is a magical portal, while a stone archway allows access back to "
    "the grove.");

  SetItems ( ([

    ({"tower","mist","mists"}) :
       "The tower is a tribute to the element air and the greater "
       "glory of Zaxan.",

    ({"wall","walls","ceiling","floor"}) :
       "There is no clear view of the tower's boundaries, as they "
       "forever change from moment to moment.",

    ({"cloud","altar"}) :
       "The altar is formed of cloud and is sacred to the Lord of "
       "elemental energies.",

    ({"symbol","element","elements"}) :
       "The symbol of air, one of the four pure elements.",

    ({"portal","plane"}) :
       "By the images projected from the portal it appears to lead to "
       "another plane of existence.",

    ({"archway","grove"}) :
       "The stone archway projects the image of the grove of the "
       "Magildan Temple.",
    ]) );

  SetItemAdjectives( ([
    "tower" : ({"moulded","of","air","translucent","transient"}),
    "wall" : ({"shifting","changing"}),
    "altar" : ({"large"}),
    "symbol" : ({"of","air","indented"}),
    "portal" : ({"magical","of","existence"}),
    "archway" : ({"stone"}),
    ]) );

  SetInventory ( ([
    JID_NPC + "/air_elem" : 2,
    ]) );

  SetSmell ( ([
    "default" : "The air is oddly odourless."]) );

  SetEnters ( ([
    "portal" : JID_ROOM + "/temple/greathall",
  ]) );

  SetExits ( ([
    "out" : JID_ROOM + "/temple/grove",
  ]) );

}

