#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

int PreExit();

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("stone staircase");
   SetLong("Torches flare up against the stone walls, leading one down "
           "into the earth.  The staircase twists as it heads downward, "
           "and dusty tracks show that someone has been through "
           "earlier.  A door leads out to the north, made of very solid "
           "wood.");
   SetItems( ([
                ({ "dusty trcks","dusty track","tracks","track" }) :
                   "The tracks look solemnly placed, as if they "
                   "were part of a procession of some kind.",
                ({ "stone staircase","staircase","stairs","stair" }) :
                   (: GetLong :),
                ({ "stone walls","stone wall","wall","walls",
                   "torches","torch","south wall","large stones",
                   "large stone","stone","stones","blocks of stone",
                   "block of stone","block","blocks" }) :
                   "Blocks of stone, carefully fitting together in "
                   "rectangular conformity, make up most of the walls.  "
                   "However, the south wall is made off large stones, "
                   "fit together like interlocking puzzle pieces.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/altar_at",
           ]) );
   AddExit("down",VC_ROOM + "/c_hall1",(: PreExit :));
}

int PreExit() {
   if(!userp(this_player())) return 0;
   return 1;
}
