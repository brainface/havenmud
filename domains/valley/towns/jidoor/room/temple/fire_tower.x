/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: fire_tower.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: inside the Tower of Fire in the Magildan Temple
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"
inherit LIB_ROOM;

static void create()  {
    room::create();

  SetTown ("Jidoor");
  SetDomain ("Valley");
  SetClimate ("indoors");
  SetAmbientLight (50);
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);

  SetShort ("the Tower of Fire in the Magildan Temple");
  SetLong (
    "The brilliance of the tower blinds momentarily upon entrance, "
    "and the heat that radiates from the wall is nearly "
    "unbearable.  As the eyes adjust, it can be seen that this tower "
    "is truly a monument to the glory of fire, one of the four basic "
    "elements.  Flames crawl across the stone walls like spiders, while "
    "the stone floor is covered with scattered coals.  The ceiling "
    "stretches beyond sight.  A small altar sits in the center of the "
    "tower, glowing white with intense heat.  It is marked with the "
    "symbol of fire.  Hovering slightly behind the altar is a magical "
    "portal, while the archway leads back to the grove to the southeast.");

  SetItems ( ([
    
    ({"tower"}) : 
       "The tower is dedicated to the element of fire and the greater "
       "glory of the Lord of Elemental Energies.",

    ({"wall","walls"}) :
       "The walls are built from granite, yet allow the passage of fire "
       "as easily as if they were kindling.",
    
    ({"fire","flame","flames","pattern"}) :
       "The small flames dance in and out of existence as they weave "
       "a hypnotic pattern on the wall.",

    ({"floor","coals"}) :
       "Red hot coals litter the floor, increasing the temperature "
       "of the tower.",

    ({"ceiling"}) :
       "Although well lit, the light does not allow for a clear view of "
       "the ceiling.",

    ({"altar"}) :
       "The alter is forged from steel, and glows white hot by the "
       "powers of the Lord of Elemental Energies.",

    ({"symbol"}) :
       "The symbol of fire has been carved into the alter, marking it as "
       "sacred to the Lord of Elemental Energies.",

    ({"portal","plane"}) :
       "By the images projected from the portal it appears to lead to "
       "another plane of existence.",
  
    ({"archway","grove"}) :
       "The stone archway projects the image of the grove of the "
       "Magildan Temple.",
    ]) );

  SetItemAdjectives( ([
    "tower" : ({"circular","brilliant"}),
    "wall" : ({"stone","hot","radiating","granite"}),
    "fire" : ({"dancing","small","crawling","hypnotic"}),
    "coals" : ({"red","hot","scattered","stone"}),
    "altar" : ({"white","hot","steel","small"}),
    "symbol" : ({"of","fire","carved"}),
    "portal" : ({"magical","of","existence"}),
    "archway" : ({"stone"}),
    ]) );

  SetInventory ( ([
    JID_NPC + "/fire_elem" : 2,
    ]) );

  SetSmell ( ([
    "default" : "The room carries the faint scent of woodsmoke."]) );

  SetListen ( ([
    "default" : "The crackling of flames fills the tower."]) );

  SetEnters ( ([
    "portal" : JID_ROOM + "/temple/greathall",
    ]) );
    
  SetExits ( ([
    "out" : JID_ROOM + "/temple/grove",  
  ]) );
    
  SetProperties ( (["no bump" : 1]) );
  SetProperties ( (["no combat" : 1]) );
  SetProperties ( (["no teleport" : 1]) );
}

