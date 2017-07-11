
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("Two bunk beds rest against one wall.  "
         "A few chests are stacked beneath the window.  "
         "A small ceramic "
         "dog rests on  the window ledge. "
         "A table and chairs are set up in the middle "
         "of the room.  ");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and has recently been swept. ",
             ({ "bunk beds", "beds", "bed"}):
                 "The bunk beds look fairly comfortable "
                 "and are painted bright yellow.",
         ({ "chests", "chest"}):
                "All of the chests are about the same size "
                "and are painted in bright colors.  There "
                "are no locks on them.  They are used to "
               "store possessions.",
        ({"window"}) : "The window lets light in. ",
        ({"walls", "wall"}) :
             "The walls are painted light blue. ",
        ({"table"}) : "The table is simple yet sturdy.  "
                "It has been painted a pale pink. ",
        ({"chairs", "chair"}) :
               "The simple, sturdy chairs are the "
               "same pale pink as the table.  ",
        ({"dog", "ledge"}): "The small ceramic dog "
                "rests on the window ledge." 
             ]) );
    SetItemAdjectives( ([
                    "chairs" : ({"chair"}),
                    "chests" : ({"several"}),
                    "dog" : ({"small", "ceramic"}), 
                    "ledge" : ({"window"}),
                    "beds" : ({"two"})
                    ]) );
    SetSmell( ([
                "default" : "The faint hint of cedar "
                                  "wafts through the wagon. "
    
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
