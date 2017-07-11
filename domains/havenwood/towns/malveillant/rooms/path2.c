/*  Portia  12-12-98
    The path leading to Res2.c
    version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("an overgrown path");
 SetClimate("underground");
 SetExits( ([
   "southwest" : MAL_ROOMS + "center1",
   "south" : MAL_ROOMS + "path3",
   "west" : MAL_ROOMS + "path1",
   ]) );
 SetInventory( ([
   MAL_NPC + "citizen2" : 1,
   ]) );
 SetListen( ([
   "default" : "The sounds of civilization are all around.",
   ]) );
 SetSmell( ([
   "default" : "The area smells strongly of earth.",
   ]) );
 SetLong("This portion of the path is the only "
   "part that seems to have been ignored. There "
   "is a thick coating of moss all around, as well "
   "as several small weeds. To the north lies a small "
   "obsidian building that also seems to need some work.");
 SetItems( ([
   ({"portion", "path"}) : (:GetLong:),
   ({"coating", "moss", "coating of moss"}) : "The moss "
       "seems to be everywhere.",
   ({"weeds", "weed"}) : "The scattered weeds should have "
       "been pulled long ago.",
   ({"building"}) : "The building seems to be in minor "
       "disrepair.",
   ]) );
 SetItemAdjectives( ([
   "portion" : "overgrown",
   "coating" : "thick",
   "weeds" : ({"several", "scattered", "small"}),
   "building" : ({"small", "obsidian"}),
   ]) );
 SetEnters( ([
   "building" : MAL_ROOMS + "res2",
   ]) );
 }

