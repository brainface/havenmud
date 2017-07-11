
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
                 " at the back of the wagon.  A bowl of " 
                 "oranges rests on the table.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and kept impeccably clean. ",
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
                "are no locks on them.  They are used to "
                "store possessions.",
           ({"walls", "wall"}) : "The walls are lavender. ",
           ({"table"}) : "The table is simple yet sturdy.  "
               "Paintings of brightly colored birds adorn "
               "the top of the table.",
        ({"chairs", "chair"}) : 
               "The chairs are simple and sturdy.  "
               "They are painted blue with white clouds"
               "running down the backs and the legs. ",
        ({"paintings", "birds", "top", "painting","bird"}) : 
              "Bright birds are painted on the tabletop.",
        ({"clouds", "backs", "legs", "cloud", "back",  
                "leg"}) : "Fluffy white "
              "clouds are painted on the backs and legs "
              "of the chairs. ",
             ]) );  
    SetItemAdjectives( ([
                    "chairs" : ({"chair"}),
                    "chests" : ({"several"}),
                    "cushions" : ({"large"}),
                    "piles" : ({"small"}),
                    "birds" : ({"brightly colored"}),
                     "top" : ({"table top"}),
                     "clouds" : ({"white"})                            
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
                       "out" : C_ROOM + "camp6"
                  ]) );
}
