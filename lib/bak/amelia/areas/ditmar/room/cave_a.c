#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(20);
   SetShort("inside Ditmar");
   SetLong("Stalagmites grow from the bottum of the cave, mostly against "
           "walls, with paired stalactites above.  There are openings in "
           "the general flow to the north and west; small alcolves are "
           "formed there leading into smaller branches.  To the east and "
           "southwest, the caves continue.");
   SetItems( ([
                ({ "small alcolves","small alcolve","alcolve",
                   "alcoves","openings","opening" }) :
                   "To the north and west, there are openings in the "
                   "cave that lead into other caves.  The sign is "
                   "obviously intended to refer to them.",
                ({ "ditmar","town","city","cave" }) :
                   (: GetLong :),
                ({ "growing stalagmite","stalagmites","stalagmite" }) :
                   "The stalagmites grow up from the bottum of the "
                   "cave, and would cover the entire area, save the "
                   "fact that the main path has been polished free of "
                   "Them.  Some seem to glow in different shades and "
                   "colors.",
                ({ "growing stalactites","growing stalactite",
                   "stalactite","stalactites" }) :
                   "The stalactites hang down from the top of the "
                   "cave, with little nubs covering all of the "
                   "ceiling, though it is obvious they have been "
                   "forcefully worn away to make it possible for the "
                   "taller people to move through Ditmar freely.  Like "
                   "the stalagmites, they are let to grow free near the "
                   "edges of the cave, and some are tinted different "
                   "colors.",
           ]) );
   SetListen( ([
                 "default" : "Drips of invisible water can be heard.",
            ]) );
   SetSmell( ([
                "default" : "The air smells fresh and clean, though "
                   "full of rocks and crisp cool dampness.",
           ]) );
   SetExits( ([
                "east"      : D_ROOM + "/ingates",
                "southwest" : D_ROOM + "/cave_b",
                "west"      : D_ROOM + "/barr",
                "north"     : D_ROOM + "/libr",
           ]) );
   SetInventory( ([
                    D_OBJ + "/sign_c" : 1,
               ]) );
}