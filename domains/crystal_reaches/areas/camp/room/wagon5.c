
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
         "are stacked next to the beds.  A single rug "
         "rests on the floor in the middle of the wagon. ");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and kept impeccably clean. ",
             ({ "bunk bed"}):
                 "The blue bunk bed appears to be a bit "
                 "hard but well used.",
         ({ "chests", "chest"}):
                "All of the chests are about the same size "
                "and are painted in bright colors.  There "
                "are no locks on them.  They are used to "
                "store possessions.",
        ({"walls", "wall"}) :
                "The walls are painted sea green. ",
        ({"table"}) : "The table is simple yet sturdy.  "
               "It is painted the same blue as the beds. ",
        ({"chairs", "chair"}) :
              "The chairs are simple and sturdy. "
               "They are painted blue to match the table. ",
        ({"bed", "single bed"}): "The single bed is also "
               "painted blue but looks more comfortable "
               "than the bunk beds.  It looks like it could "
               "easily fit two people. ",
         ({"window"})  : "The window lights the wagon "
               "with natural light. ",
         ({"rug"}) : "The rug is deep purple in color. "
             ]) );
    SetItemAdjectives( ([
                    "chairs" : ({"chair"}),
                    "chests" : ({"several "}),
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
                       "out" : C_ROOM + "camp2"
                  ]) );
}
