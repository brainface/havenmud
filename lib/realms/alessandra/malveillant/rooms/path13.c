/*   Portia   12-9-98
     The path to the bank.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("an orderly path");
 SetClimate("underground");
 SetExits( ([
   "north" : MAL_ROOMS + "center2",
   "west" : MAL_ROOMS + "path14",
   "east" : MAL_ROOMS + "path12",
   ]) );
 SetInventory( ([
   ]) );
 SetListen( ([
   "default" : "The path is exceptionally quiet here.",
   ]) );
 SetSmell( ([
   "default" : "The area smells of earth.",
   ]) );
 SetLong("This path has a striking order to it. The caregiver "
   "must be one who takes great pride in organizing things. "
   "The path is outlined with stones and if one were to spend "
   "their time counting them, they would find there are exactly "
   "twenty on either side of the path. This well planned path "
   "leads south to a very official looking obsidian building.");
 SetItems( ([
   "path" : (:GetLong:),
   ({"building", "bank"}) : "This large building looks very official.",
   ({"stones", "stone"}) : "There are exactly forty stones here.",
   ({"sides", "side", "side of the path"}) : "The sides are lined with "
       "stones.",
   ]) );
 SetItemAdjectives( ([
   "path" : ({"orderly", "striking", "outlined", "planned", "well"}),
   "building" : ({"official", "looking", "obsidian"}),
   ]) );
 SetEnters( ([
   ({"building", "bank"}) : MAL_ROOMS + "bank",
   ]) );
 }


