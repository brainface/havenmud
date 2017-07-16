
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is small but comfortable.  "
                 "A hammock is set up along the walls.  "      
                 "The walls between the "
                 "hammocks are lined with chests.  A "
                 "small table and chairs sit in the middle "
                 "of the room.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and is clean.",
             ({"hammocks", "hammock"}):
                 "The hammocks are big enough for a large "
                 "man to sleep in.  They are all white.",
            ({ "chests", "chest"}):
                "The chests are all about the same size and "
                "brightly colored.  They are unlocked and "
                "used for storage. ",                
        ({"walls", "wall"}) :
             "The walls are whitewashed. ",
        ({"table"}) : "The table is simple yet sturdy.  "
              "It is painted a soft green.  ",
        ({"chairs", "chair"}) :
                "The chairs are simple and sturdy.  "
               "They are painted to match the table. ",]) );
    SetItemAdjectives( ([
                    "chests" : ({"several"}),
                    "hammocks" : ({"three"})
                    ]) );
    SetSmell( ([
                "default" : "The air is filled with the scent "
                                  "of fresh bread. "
    
              ]) );
    SetListen( ([
                "default" :  "A few loud noises from "
                                  "outside occasionally pierce "
                                  "the peaceful quiet. "
             ]) );
    SetInventory( ([ C_NPC + "teen" :1]) );
    SetClimate("indoors");
    SetExits( ([
                       "out" : C_ROOM + "camp4"
                  ]) );
}
