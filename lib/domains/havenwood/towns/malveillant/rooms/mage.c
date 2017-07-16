/*  Portia 12-11-98
    The mage's room.
    version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a large workroom");
 SetClimate("indoors");
 SetExits( ([
   "south" : MAL_ROOMS + "tutor",
   "west" : MAL_ROOMS + "roy_ent",
   ]) );
 SetListen( ([
   "default" : "This area is very quiet.",
   ]) );
 SetSmell( ([
   "default" : "The room smells oddly.",
   ]) );
 SetInventory( ([
   MAL_NPC + "roy_evok" : 1,
   MAL_NPC + "roy_enc" : 1,
   ]) );
 SetLong("This room is the workroom of the "
   "royal mages. They have been hired because they "
   "are the best in their respective fields. "
   "They study here to become better able to serve "
   "their prince and learn more about their trade. "
   "They are also responsible for training mages to "
   "follow in their footsteps when they are no more.");
 }
