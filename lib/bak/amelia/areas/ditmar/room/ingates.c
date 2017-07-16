#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(10);
   SetShort("inside the Gates of Ditmar");
   SetLong("The Gates of Ditmar stretch high to the east, protecting "
           "Ditmar.  The floor is worn smooth, polished free of any "
           "stalagmites that might be stuck there, but some stalactites "
           "hang down slightly from the ceiling.  They have also been "
           "worn down.  The cave continues to the west and south.  The "
           "cave to the south seems smaller.");
   SetItems( ([
                ({ "Ditmar caves","caves","cave","ditmar caves",
                   "ditmar cave" }) :
                   (: GetLong :),
                ({ "Ditmar","ditmar","city","town","underground city" }) :
                   (: GetLong :),
                ({ "smooth floor","floor" }) :
                   "To make it easy to walk through, Ditmar's floors have "
                   "been polished smooth, free of the stalagmites that "
                   "are easy to trip on.  Near the sides of the cave, "
                   "however, some stalagmites flourish in large sizes.",
                ({ "slightly bumpy ceiling","ceiling" }) :
                   "Stalactites are few and far between on the ceiling, "
                   "and most are far, but like the stalagmites, a few "
                   "are allowed near the edges where they won't hit "
                   "the taller citizens on the head.",
                ({ "stalactites and stalagmites","stalactite",
                   "stalactites","stalagmites","stalagmite" }) :
                   "Both the ceiling and the floor have been mostly "
                   "freed of stalactites and stalagmites to make movement "
                   "more convenient to those living in Ditmar.  Near the "
                   "walls, they grow rather freely and beautifully, "
                   "with a variety of colors and shapes.",
           ]) );
   SetListen( ([
                 "default" : "Water drips every once in a while from an "
                    "unseen area.",
            ]) );
   SetSmell( ([
                "default" : "Though deep beneath the surface, the air is "
                   "not so much musty as it is minerally and wet.",
           ]) );
   SetExits( ([
                "east"  : D_ROOM + "/atgates",
                "west"  : D_ROOM + "/cave_a",
                "south" : D_ROOM + "/townhall",
           ]) );
   SetDoor("east", D_ROOM + "/gate");
   SetInventory( ([
                    D_OBJ + "/sign_b" : 1,
               ]) );
}