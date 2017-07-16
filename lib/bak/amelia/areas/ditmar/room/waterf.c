#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(24);
   SetShort("near a waterfall");
   SetLong("There are many stalagmites and stalactities clustered here, "
           "surrounding the waterfall and the small pool of water below "
           "it.  The water flows out some underwater hole towards the "
           "east side of the room, so it effectively blocks "
           "movement to the south, as the waterfall comes from "
           "the west.  The only way out is to the northwest.");
   SetItems( ([
                ({ "Ditmar Falls","falls","waterfall","water",
                   "ditmar falls" }) :
                   "The Ditmar Falls, as this waterfall is called, "
                   "comes crashing down from the western side of the "
                   "cave.  The water flows to the east side of the "
                   "cave, where it has formed a small pool.",
                ({ "small pool of water","small pool","pool",
                   "pool of water","water" }) :
                   "The pool of water is near the east side of the "
                   "cave, where a hole underwater must drain it.  "
                   "The hole cannot be seen, however, though the water "
                   "is quite clear.",
                ({ "stalagmites and stalactites","stalagmites",
                   "stalagmite","stalactite","stalactites" }) :
                   "The stalagmites and stalactites are all over here, "
                   "though some have been worn down by Ditmar citizens, "
                   "to make it easier to get at their water source.",
                ({ "waterfall cave","cave","room" }) :
                   (: GetLong :),
           ]) );
   SetListen( ([
                 "default" : "The Ditmar Falls make a great deal of "
                    "noise as the water crashes down and splatters the "
                    "surrounding area.",
            ]) );
   SetExits( ([
                "northwest" : D_ROOM + "/cave_b",
           ]) );
   SetInventory( ([
                    D_OBJ + "/wbucket" : 1,
                    D_OBJ + "/sign_f" : 1,
               ]) );
}