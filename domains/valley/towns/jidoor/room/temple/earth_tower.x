/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: earth_tower.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: the Tower of Earth in the Magildan Temple
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
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);

  SetShort ("the Tower of Earth in the Magildan Temple");
  SetLong (
    "The tower appears to have been ripped from the very earth itself; "
    "the walls are jagged and consist of clay, stone and petrified wood.  "
    "The floor is a patch of grass, while many stalactites hang down from "
    "the ceiling.  The roots weave in and out of the floor like thread "
    "through cloth, and coalesce into the rough form of an alter in the "
    "center of the tower.  Carved into the altar is the symbol of earth. "
    "Slightly behind the altar is a magical portal, while an archway "
    "leads back to the grove of the Magildan Temple."); 

  SetItems ( ([
  
    ({"tower","earth"}) : 
       "The tower has been fashioned by the Lord of Elemental Energy, using the earth "
       "that was in the area.",

    ({"wall","walls","rock","rocks","clay","stone","wood"}) :
       "The walls are mostly clay, baked hard with elemental fire.  "
       "Rocks and petrified wood that were in the earth at the time of the "
       "tower's creation have been permanently fused into the walls.",

    ({"floor","grass"}) :
      "The grass is green and vibrant with the life.",

    ({"ceiling","stalactite","stalactites"}) :
       "The stalactites are roughly 6 feet in length, and have needle "
       "sharp points.",
  
    ({"root","roots"}) :
       "The roots are thick and full of knots.  They coalesce in the "
       "of the tower to form the altar.",

    ({"altar"}) :
       "The altar is formed from roots and is marked with the symbol of "
       "earth.",

    ({"symbol"}) :
       "The smybol of earth has been carved into the altar, marking it as "
       "sacred to the Lord of Elemental Energies.",

    ({"portal","plane"}) :
       "By the images projected from the portal it appears to lead to "
       "another plane of existence.",
  
    ({"archway","grove"}) :
       "The stone archway projects the image of the grove of the "
       "Magildan Temple.",    
    ]) );

  SetItemAdjectives( ([
    "symbol" : ({"of","earth"}),
    "wall" : ({"clay","baked","hard","jagged","fused"}),
    "tower" : ({"ripped","fashioned","earth"}),
    "grass" : ({"patch","of"}),
    "root" : ({"thick","full","of","knots","weaving","coalescing"}),
    "stalactite" : ({"needle","sharp","many"}),
    "symbol" : ({"carved"}),
    "portal" : ({"magical"}),
    "archway" : ({"stone"}),
    ]) );

  SetInventory ( ([
    JID_NPC + "/earth_elem" : 2,
    ]) );

  SetSmell ( ([
    "default" : "The musky smell of freshly churned earth is overpowering."
    ]) );

  SetListen ( ([
    "default" : "It is eerily silent."]) );

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



