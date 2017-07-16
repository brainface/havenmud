/*   Portia  12-11-98
     The sleeping room of the inn.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a beautiful bedroom");
 SetProperty("no attack", 1);
 SetProperty("no magic", 1);
 SetClimate("indoors");
 SetExits( ([
   "down" : MAL_ROOMS + "inn",
   ]) );
 SetInventory( ([
   ]) );
 SetSmell( ([
   "default" : "The smell of food drifts in from the "
       "north",
   ]) );
 SetListen( ([
   "default" : "The noise of the inn is faint here.",
   ]) );
 SetLong("This bedroom is lavishly furnished. "
   "It is obvious that someone took great pride in "
   "making sure this is the most beautiful room in "
   "Malveillant. "
   "A large four-poster bed stands in the corner near "
   "a finely-crafted chest of drawers. A large window "
   "has been carved out of the northern wall which "
   "overlooks the beautiful, shimmering town of "
   "Malveillant.");
 SetItems( ([
   ({"bedroom"}) : (:GetLong:),
   ({"bed"}) : "The beautiful bed looks comfortable.",
   ({"chest", "chest of drawers"}) : "The chest looks rather "
       "expensive.",
   ({"wall", "window", "town", "view"}) : "The view from here "
       "is excellent.",
   ]) );
 SetItemAdjectives( ([
   "bedroom" : ({"beautiful", "lavish", "furnished"}),
   "bed" : ({"large", "four-poster", "comfortable"}),
   "chest" : ({"fine", "finely-crafted", "expensive"}),
   "wall" : ({"northern", "beautiful", "shimmering"}),
   ]) );
 }
