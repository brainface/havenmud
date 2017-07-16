#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(10);
   SetShort("inside Ditmar");
   SetLong("Caves split off from here to the northeast, east, southeast, "
           "south, and west; the caves to the east and south are the "
           "smallest, probably leading into some sort of room or "
           "specified area.  Stalagmites and stalactites decorate the "
           "edges of the cave, though towards the center of the cave, "
           "they have been prevented from growth.  There seem to be "
           "more of them towards the center of the cave to the south.");
   SetItems( ([
                ({ "Ditmar","ditmar","cave","caves","town","city" }) :
                   (: GetLong :),
                ({ "eastern cave","east cave","cave" }) :
                   "The cave to the east is pretty small, compared to the "
                   "size of the one out here, but it seems to open up "
                   "a ways back.",
                ({ "southern cave","south cave","cave" }) :
                   "The southern cave has something over it so that "
                   "no one can peek in uninvited, but it looks like "
                   "anyone could walk through.",
                ({ "stalagmites and stalactites","stalagmite",
                   "stalagmites","stalactities","stalactite" }) :
                   "Around the sides of the cave, stalagmites and "
                   "stalactites have been allowed to form in all their "
                   "glory.  Some appear similar to other, more familiar "
                   "and every day shapes, and others are tinted shades of "
                   "blue, green, and orange.",
                ({ "southeast cave","southeastern cave","cave" }) :
                   "While in most of Ditmar, the stalagmites and "
                   "stalactites have been carefully put back, the "
                   "cave to the southeast has some growing towards the "
                   "center that have hardly been touched.",
           ]) );
   SetSmell( ([
                "default" : "The air smells crisp and full of minerals.",
           ]) );
   SetListen( ([
                 "default" : "Some rushing noise comes from the southeast.",
            ]) );
   SetExits( ([
                "northeast" : D_ROOM + "/cave_a",
                "east"      : D_ROOM + "/cemet",
                "southeast" : D_ROOM + "/waterf",
                "south"     : D_ROOM + "/gs",
                "west"      : D_ROOM + "/cave_c",
           ]) );
   SetInventory( ([
                    D_OBJ + "/sign_d" : 1,
                    D_OBJ + "/sign_e" : 1,
               ]) );
}