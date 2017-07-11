#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("narrowing valley");
   SetDomain("Valley");
   SetLong("The valley narrows here, heading off in a canyon to the "
           "northeast, the cliff walls growing higher as well.  "
           "To the south, the valley widens, with directions heading "
           "off to the southwest as well.  Deciduous trees flourish "
           "around the cliff, but do not block one's path in any "
           "directions; the cliff has done enough of that already.");
   SetItems( ([
                ({ "narrowing valley","valley","canyon" }) :
                   (: GetLong :),
                ({ "cliff","cliff walls","cliff wall","wall","walls",
                   "large slabs of gray rock","large slabs","slabs",
                   "large slab of gray rock","large slab","slab",
                   "gray rock","rock","grey rock","large slabs of "
                   "grey rock","large slab of grey rock" }) :
                   "The cliff rises high up, growing higher and higher "
                   "to the northeast, but lowering slightly to the "
                   "south.  Large slabs of gray rock make up the " 
                   "cliff walls, with little color to them.  Some dirt "
                   "has managed to find room to hide among the "
                   "rock.",
                ({ "dirt ground","ground","soil","dirt","rich soil",
                   "healthy soil" }) :
                   "The ground is made of rich and healthy soil for "
                   "the trees to grow in, as well as other plants in "
                   "the area.",
                ({ "forest plants","forest plant","plant","plants" }) :
                   "A variety of plants speckle the space between "
                   "the trees.  They flourish happily in the rich "
                   "soil, and a couple poke out of the cliff in its "
                   "small dirt pockets, but those do not seem as healthy.",
                ({ "cliff dirt","dirt","small dirt pockets","pockets",
                   "small dirt pocket","pocket","dirt pockets",
                   "dirt pocket","small pocket","small pockets" }) :
                   "The dirt on the cliff is similar to the dirt on the "
                   "ground, but it seems less rich and healthy than the "
                   "soil the trees are flourishing in.  Some plants "
                   "grow in the cliff, but not many.",
                ({ "deciduous trees","deciduous tree","tree","trees" }) :
                   "Trees gather all over the valley, even in the "
                   "canyon to the northeast, but not so thick as "
                   "to prevent movement.",
           ]) );
   SetObviousExits("northeast, south, southwest");
   SetExits( ([
                "northeast" : JD_ROOM + "/canyon_2",
                "south"     : JD_ROOM + "/valley_7",
                "southwest" : JD_ROOM + "/valley_6",
           ]) );
   SetInventory( ([
                    JD_NPC + "/chameleon" : 3+random(3),
               ]) );
}
