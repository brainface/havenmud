/*   Portia 12-11-98
     The path to the palace.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a moss lined path");
 SetClimate("underground");
 SetExits( ([
   "north" : MAL_ROOMS + "path3",
   "west" : MAL_ROOMS + "path5",
   "northwest" : MAL_ROOMS + "center1",
   ]) );
 SetListen( ([
   "default" : "There are sounds coming from the south.",
   ]) );
 SetSmell( ([
   "default" : "The area smells earthen.",
   ]) );
 SetInventory( ([
   MAL_NPC + "guard1" : 1,
   MAL_NPC + "guard2" : 1,
   MAL_NPC + "citizen1" : 1,
   MAL_NPC + "citizen2" : 1,
   ]) );
 SetLong("Ths path appears to lead somewhere very "
   "important. The green moss that lines the trail "
   "is trimmed to look like a hand-made rug. What "
   "appears to be a palace lies to the south. Near the "
   "huge entrance there is a large plant. The symbol "
   "of the Soirin religion is carved into the door of "
   "the palace.");
 SetItems( ([
   "path" : (:GetLong:),
   "moss" : "The moss leads to the palace.",
   "palace" : "The palace is south of here.",
   "plant" : "The plant is rare for this climate.",
   "symbol" : "The symbol is carved in the door.",
   "door" : "Oddly, the door to the palace is wide open.",
   ]) );
 SetItemAdjectives( ([
   "path" : ({"moss lined"}),
   "moss" : ({"green", "soft", "trimmed"}),
   "palace" : ({"obsidian", "huge"}),
   "symbol" : "soirin",
   ]) );
 SetEnters( ([
   "palace" : MAL_ROOMS + "roy_ent",
   ]) );
 }
