#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("an opulent guest room");
   SetLong("Tapestries have been hung over the chill stone walls to "
           "add a warmer atmosphere to the room; Accompagnied with "
           "some plain rugs, the room is almost comfortable despite "
           "the stones.  A door leads out to the west.");
   SetItems( ([
                ({ "opulent guest room","opulent room","guest room",
                   "room" }) :
                   (: GetLong :),
                ({ "chill stone walls","chill walls","stone walls",
                   "tapestries","chill stone wall","chill wall",
                   "stone wall","tapestry","plain rugs","plain rug",
                   "rug","rugs","floor" }) :
                   "The stone walls are chill and cold, but the "
                   "tapestries which cover the walls the rugs on the "
                   "floor warm the room up a lot.",
           ]) );
   SetExits( ([
                "west"  : VC_ROOM + "/hall4",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
