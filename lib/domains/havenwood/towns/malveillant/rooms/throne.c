/*   Portia  12-11-98
     The throne room
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("the throne room");
 SetClimate("indoors");
 SetExits( ([
   "east" : MAL_ROOMS + "tutor",
   "north" : MAL_ROOMS + "roy_ent",
   ]) );
 SetListen( ([
   "default" : "The room is very noisy.",
   ]) );
 SetSmell( ([
   "default" : "The room smells of food.",
   ]) );
 SetInventory( ([
   MAL_NPC + "prince" : 1,
   MAL_NPC + "dancer" : 1,
   ]) );
 SetNewsgroups( ({ "town.malveillant" }) );
 SetLong("This is the throne room of Prince Marikian. "
   "A long banquet table sits off to one side of the "
   "room full of untouched food. The large throne is "
   "at the southernmost end of the room, and a large "
   "hand-woven rug leads the way to the throne. Many "
   "servants are scampering around trying to fill the "
   "young prince's every need or desire.");
 SetItems( ([
   "table" : "The table is full of food.",
   "food" : "The food has yet to be touched.",
   "throne" : "Prince Marikian's throne is absolutely huge.",
   "rug" : "The rug leading to the throne is quite pretty.",
   ({"servants", "servant"}) : "The servants look very busy.",
   ]) );
 SetItemAdjectives( ([
   "table" : ({"large", "banquet", "full"}),
   "food" : ({"untouched"}),
   "throne" : ({"huge", "large"}),
   "rug" : ({"hand-woven", "pretty"}),
   "servants" : "busy",
   ]) );
 }
