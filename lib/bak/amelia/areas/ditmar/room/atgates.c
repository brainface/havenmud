#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(10);
   SetShort("at the Gates of Ditmar");
   SetLong("A long, skinny tunnel heads up into the rest of the world "
           "near the rising ceiling of this cave.  Water drips from the "
           "tips of the stalactites hanging from the roof of the cave, "
           "often landing on similar stalagmite formations on the floor.  "
           "To the west, half-hidden among the beautiful formations, "
           "are the Gates of Ditmar, leading into the underground city.");
   SetItems( ([
                ({ "Ditmar","underground city","ditmar","city","town" }) :
                   "The area beyond the gates does not look much different "
                   "from here, only it is refined and polished.",
                ({ "stalactite formations","formation","stalactites",
                   "stalactite","formations" }) :
                   "The stalactites cast shadows in the room, but "
                   "are still glorius and beautiful.  Some are faintly "
                   "tinged blue or orange-red, and a few have connected "
                   "to their counterparts below.",
                ({ "stalagmite formations","formation","formations",
                   "stalagmite","stalagmites" }) :
                   "The stalagmites crouch curiously beneath the "
                   "beautiful stalactites above them, but some seem to "
                   "stand tall and proud or have their own peculiar "
                   "personalities to them.  Others are shaped like "
                   "familiar objects.",
                ({ "dripping water","water" }) :
                   "Water drips down from the ceiling, skittering down the "
                   "stalactites in old, familar paths.",
                ({ "long skinny tunnel","tunnel" }) :
                   "The tunnel has not been greatly improved upon, as "
                   "very few on the citizens of Ditmar have found great "
                   "inclinations to leave the underground.  It is quite "
                   "rough and some spots could make it difficult for the "
                   "larger of adventures to pass through.",
                ({ "rising ceiling","ceiling","roof" }) :
                   "Near the ceiling of the cave is the skinny tunnel "
                   "leading out of Ditmar.  The ceiling itself rises "
                   "and spreads out to the west; the cave expands to allow "
                   "room for the compact city of Ditmar.  Stalactites "
                   "hang down from the ceiling, some connecting to the "
                   "stalagmites below.",
                ({ "cave near ditmar","cave" }) : (: GetLong :),
           ]) );
   SetItemAdjectives( ([
                         "tunnel" : ({ "long","skinny" }),
                         "ceiling" : ({ "high","rising" }),
                         "water" : ({ "dripping" }),
                         "stalagmite" : ({ "beautiful","stalagmite" }),
                         "stalactite" : ({ "beautiful","stalactite" }),
                    ]) );
   SetListen( ([
                 "default" : "Water drips from the ceiling occasionally.",
            ]) );
   SetSmell( ([
                "default" : "The air has the tinged smell of being deep "
                   "underground, far from the open, fresh air, hidden "
                   "among rocks and minerals.",
           ]) );
   SetExits( ([
                "up"   : "out",
                "west" : D_ROOM + "/ingates",
           ]) );
   SetDoor("west",D_ROOM + "/gate");
   SetInventory( ([
                    D_OBJ + "/sign_a" : 1,
                    D_NPC + "/gatekeep" : 1,
               ]) );
}