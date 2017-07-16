#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(10);
   SetShort("Ditmar Tavern");
   SetLong("The tavern is a plain room with nothing to adorn any of the "
           "walls; there are even no stalagmites or stalactites or "
           "other beautiful rock formations.  Stone benches, stools, "
           "chairs, tables, and even a stone counter make up the "
           "the furniture of the tavern.  A tunnel leads out to the east.");
   SetItems( ([
                ({ "Ditmar Tavern","tavern","ditmar tavern","cave","room",
                   "plain room" }) :
                   (: GetLong :),
                ({ "plain walls","walls","wall" }) :
                   "The walls are plain stone, and closer examination "
                   "reveals signs that this entire room has been carved "
                   "out.",
                ({ "stone furniture","furniture","benches","bench",
                   "stools","stool","chair","chairs","tables","table",
                   "counter" }) :
                   "The stone furniture is plain, just like the rest of "
                   "the room, and much of it is attached to the ground.  "
                   "When the room was carved out, the Mar must have "
                   "planned for this to be a tavern and left some stone "
                   "in place for items like tables and chairs.",
           ]) );
   SetItemAdjectives( ([
                         "walls" : ({ "plain" }),
                         "furniture" : ({ "stone" }),
                    ]) );
   SetSmell( ([
                "default" : "The tavern smells like a typical "
                   "bar.",
           ]) );
   SetListen( ([
                 "default" : "Loud noises of singing and laughter fill "
                    "the room.",
            ]) );
   SetExits( ([
                "east" : D_ROOM + "/cave_c",
           ]) );
   SetInventory( ([
                    D_NPC + "/barkeep" : 1,
                    D_NPC + "/rogue" : 1,
                    D_NPC + "/ranger" : 1,
               ]) );
}