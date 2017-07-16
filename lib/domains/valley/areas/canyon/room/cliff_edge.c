#include <lib.h>      
#include "../jidnewbi.h"
inherit LIB_ROOM;
#define WORLD "/domains/valley/virtual/valley/0,40"
 
int PreExit();

static void create() {
   room::create();
   SetDomain("Valley");
   SetShort("at the edge of a cliff");
   SetLong("Trees hang precariously over the edge of the cliff, "
           "some looking as if they are ready to topple over right "
           "now.  A path leads down the cliff; it's steep but it "
           "looks like it could be climbed both ways.  A way through "
           "the trees leads back to the road to the west.");
   SetItems( ([
                ({ "steep path","path" }) :
                   "The path leads down the cliff in a meandering "
                   "way, but seems to have chosen the best possible "
                   "direction.",
                ({ "edge of a cliff","edge of cliff","edge","cliff" }) :
                   (: GetLong :),
                ({ "decidious trees","decidious tree","tree","trees" }) :
                   "The decidious trees hang over the cliff, but "
                   "some were wise enough to plant themselves farther "
                   "from the cliff.",
           ]) );
   SetExits( ([
                "down"  : JD_ROOM + "/cliff_bottom",
           ]) );
    AddExit("west",WORLD,(: PreExit :));
   SetInventory( ([
                    JD_NPC + "/jay_blue" : 1,
               ]) );
}
 
int PreExit() {
   if(this_player()->GetProperty("jidnewbinoleave")) return 0;
   return 1;
} 

/* Approved by Zaxan on Sat Jan 17 03:20:37 1998. */
