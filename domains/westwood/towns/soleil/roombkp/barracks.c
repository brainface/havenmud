#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"

static void create() {
   room::create();
   SetTown("Soleil");
   
   SetShort("training grounds");
   SetLong("This open clearing is surrounded by a protective ring of "
           "trees which opens only the northeast.  A trail heads off "
           "in that direction, turning shortly after it leaves the "
           "clearing, yet it seems to turn back to the northeastern "
           "course before long.  Dark green moss grows thickly at the "
           "edges of the clearing as the ground towards its center "
           "grows more compacted and brown.");
   SetItems( ([
                ({ "compacted ground","brown ground","ground" }) :
                   "The ground is hard and brown towards the center "
                   "of the clearing, but at the edges, thick green moss "
                   "grows.",
                ({ "dark green moss","dark moss","green moss","moss",
                   "tree","trees","spruce trees","spruce tree",
                   "furry green stuff","furry stuff","green stuff",
                   "stuff","thick green moss","thick moss" }) :
                   "The moss grows under the spruce trees which form "
                   "the boundaries of the clearing.  The furry green "
                   "stuff is soft.",
                ({ "training grounds","training ground","ground","grounds",
                   "open clearing","clearing","protective ring of trees",
                   "ring of trees","protective ring","ring","trees",
                   "tree" }) :
                   (: GetLong :),
                ({ "turning trail","trail","path" }) :
                   "The path twists and turns as it heads northeast, but "
                   "follows that general direction.  It is the "
                   "only exit out of the clearing, and the trees "
                   "part only for it to pass out.  Moss grows along "
                   "it.",
           ]) );
   SetExits( ([
                "northeast" : S_ROOM + "pool",
           ]) );
   SetObviousExits("northeast");
   SetInventory( ([
                    S_NPC + "fighter_oppugno" : 1,
               ]) );
}
