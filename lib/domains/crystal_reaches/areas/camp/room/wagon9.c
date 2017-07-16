
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("A bunk bed and a single bed rest "
         "against one wall.  A small table and chairs "
         "are set up next to the window.  A few chests "
         "are stacked next to the beds.   A few clothes "
         "have been discarded on top of the chests. ");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and kept impeccably clean. ",
             ({ "bunk bed"}):
                 "The red bunk bed appears to be a bit "
                 "hard but new.",
         ({ "chests", "chest"}):
                "All of the chests are about the same size "
                "and are painted in bright colors.  There "
                "are no locks on them. They are used to "
                "store possessions.",
        ({"walls", "wall"}) : 
                "The walls are painted a warm "
                "yellow. ",
        ({"table"}) : "The table is simple yet sturdy.  "
               "It is painted the same red as the beds. ",
        ({"chairs", "chair"}) : 
               "The chairs are simple and sturdy.  "
               "They are painted red to match the table. ",
       ({"window"}) : "The window lets light in. ",
        ({"bed", "single bed"}): "The single bed is also "
               "painted red but looks more comfortable "
               "than the bunk beds.  It looks like it could "
               "easily fit three people. ",
        ({"clothes", "skirt", "blouse"}) : "A red skirt "
                "and white blouse "
               "have been left on one of the chests. "
             ]) );
    SetItemAdjectives( ([
                    "chairs" : ({"chair"}),
                    "chests" : ({"several"}),
                    "cushions" : ({"large"}),
                    "skirt" : ({"red"}),
                    "blouse" : ({"white"}),
                    "bed" : ({"red"})                            
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
    SetInventory( ([ C_NPC + "boy" : 1]) );
    SetExits( ([
                       "out" : C_ROOM + "camp4"
                  ]) );
}
