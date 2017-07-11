/*   Portia  12-11-98
     The hall of Defense.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("The Hall of Defense");
 SetClimate("indoors");
 SetExits( ([
   "out" : MAL_ROOMS + "path15",
   ]) );
 SetListen( ([
   "default" : "The room is filled with the sounds of swords.",
   ]) );
 SetSmell( ([
   "default" : "The room smells of sweat.",
   ]) );
  SetInventory( ([
   MAL_NPC + "cav_lead" : 1,
   MAL_NPC + "fight_lead" : 1,
   MAL_NPC + "oberan" : 1,
   MAL_NPC + "guard1" : 1,
   ]) );
 SetLong("The Hall of Defense is responsibe for protecting the people "
   "of Malveillant. The hall has been filled with various kinds of "
   "armour and weapons. The dark-elves of Malveillant spare no expense "
   "when it comes to the protection of their town. In the center of the "
   "hall is a flag with the silloutte of a rose, thereby displaying the "
   "Royal Guard's devotion to the Soirin faith.");
 SetItems( ([
   ({"armour", "weapons", "kinds"}) : "These items are of great value to "
       "the guardsmen.",
   ({"flag", "rose", "sillouette"}) : "The flag is the centerpiece of the "
       "hall.",
   ]) );
 }
