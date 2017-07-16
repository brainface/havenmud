
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
                 " at the back of the wagon. A small rag "
                 "doll sits in one of the chairs.  ");
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
        ({"walls", "wall"}) : 
                "The walls are painted a soft "
               " yellow to give the interior a warm "
               "feeling. ",
        ({"table"}) : "The table is simple yet sturdy.  "
               "It is painted dark green with blue legs.",
        ({"chairs", "chair"}) : 
               "The chairs are simple and sturdy.  "
               "They are painted blue with dark green "
               "legs. ",
        ("doll"): "The small rag doll looks to be new and"
               " well taken care of.  It is wearing a plain " 
               "blue dress.  ",
         ("dress") :  "The blue dress looks like it was "
               "made from a left over scrap of cloth. "
             ]) );
    SetItemAdjectives( ([
                    "chairs" : ({"chair"}),
                    "chests" : ({"several"}),
                    "cushions" : ({"large"}),
                    "doll" : ({"small", "rag", "small rag"}),
                    "piles" : ({"small"}),
                    "dress" : ({"blue"})                            
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
    SetInventory( ([ C_NPC + "kitten1" : 1]) );
    SetExits( ([
                       "out" : C_ROOM + "camp2"
                  ]) );
}
