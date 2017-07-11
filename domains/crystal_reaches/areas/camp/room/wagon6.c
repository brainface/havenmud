
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is small but comfortable.  "
                 "Large cushions are clumped in small "
                 "piles all over the floor.  Several chests are"
                 " pushed up against the walls for storage "
                 "space.   A small table and chairs are set up"
                 " at the back of the wagon. ");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "with dark brown stains beside the "
                   "spittoon. ",
             ({ "cushions", "piles", "cushion", "pile"}):
                 "Large cushions lie haphazard about the "
                 "floor.  They can be pushed into piles to "
                 "create really comfortable beds and places "
                 "to sit.  They vary a bit in size, but are all "
                 "larger than the average pillow.  Their "
                 "colors vary as much as the wagon colors. ",
         ({ "chests", "chest"}):
                "All of the chests are about the same size "
                "and are painted in bright colors.  There "
                "are no locks on them. They are used to "
                "store possessions.",
        ({"walls", "wall"}) : 
               "The walls are painted a soft "
               " yellow to give the interior a warm "
               "feeling. ",
        ({"table"}) : "The table is simple yet sturdy.  "
               "It is painted bright orange.",
        ({"chairs", "chair"}) : 
               "The chairs are simple and sturdy.  "
               "They are painted bright red. ",
             ]) );
    SetItemAdjectives( ([
                    "chairs" : ({"chair"}),
                    "chests" : ({"several"}),
                    "cushions" : ({"large"}),
                    "piles"  : ({"small"})
                    ]) );
    SetSmell( ([
                "default" : "Cedar lightly fills the air. "
    
              ]) );
    SetListen( ([
                "default" :  "A few loud noises from "
                                  "outside occasionally pierce "
                                  "the peaceful quiet. "
             ]) );
    SetClimate("indoors");
    SetExits( ([
                       "out" : C_ROOM + "camp3"
                  ]) );
}
