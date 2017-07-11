#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

int PreExit();

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(25);
   SetShort("the catacombs");
   SetLong("The light is lower here, where the torches are shorter "
           "and closer to burning out than those upstairs.  Warding "
           "symbols line the bottom stair, keeping creatures of "
           "the dark inside these catacombs.  Openings in the stone "
           "walls let one enter small vaults to the east and west, "
           "and the hall continues to the north.  Meanwhile, "
           "the staircase leads up.");
   SetItems( ([
                ({ "small vaults","small vault","vault","vaults",
                   "openings","opening" }) :
                   "Openings to the east and west lead into "
                   "the vaults of the dead.",
                ({ "upward staircase","stairs","staircase","stair",
                   "warding symbols","warding symbol","symbols",
                   "symbol","bottom stair","dust","stirred dust" }) :
                   "Symbols are etched on the bottom stair to prevent "
                   "the dead from returning to the land of the "
                   "living.  Nothing marks the other stairs "
                   "aside from some stirred dust.",
                ({ "catacombs","catacomb","crypt" }) :
                   (: GetLong :),
                ({ "stone walls","stone wall","wall","walls",
                   "torches","torch","stone","stones" }) :
                   "The torches provide the slight light down here, and "
                   "are mounted on the stone walls.  The gray "
                   "shades swirl around the stones, and it appears "
                   "that everything in here has been made very carefully "
                   "so that it will live forever.  Two openings in the "
                   "walls lead into small vaults of the dead.",
           ]) );
   SetExits( ([
                "east" : VC_ROOM + "/c_side2",
                "west" : VC_ROOM + "/c_side1",
                "north" : VC_ROOM + "/c_hall2",
           ]) );
   AddExit("up",VC_ROOM + "/c_stairs",(: PreExit :) );
   SetInventory( ([
                    VC_NPC + "/c_skel" : 2,
               ]) );
}

int PreExit() {
   if(!userp(this_player())) return 0;
   return 1;
}
