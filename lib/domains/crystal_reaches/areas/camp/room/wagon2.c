
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("Several bunks line one wall.  "
          "Underneath the bunks are few chests that hold "
          "the wagon owner's possessions.  A small table "
          "and chairs are set up in the middle of the "
          "wagon.  A rocking chair rests near the " 
          "window.  ");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and kept impeccably clean. ",
            ({"bunks", "bunk"}) : 
                  "Four shelve-like bunks line the "
                  "left wall.  The bunks are sturdy and fairly"
                  " comfortable.  ",
            ({ "chests", "chest"}):
                "All of the chests are about the same size "
                "and are painted in bright colors.  There "
                "are no locks on them. They are used to "
                "store possessions.",
            ({"walls", "wall"}) : "The walls are painted a "
                "light blue. ",
        ({"table"}) : "The table is simple yet sturdy.  "
               "Paintings of brightly attired people adorn "
               "the top of the table.  ",
        ({"people"}) : "Bright paintings of people are "
               "on the top of the table. ",
        ({"chairs", "chair"}) :
               "The chairs are simple and sturdy.  "
               "The seats are painted yellow and the legs "
               "are red. ",
        ({"rocking chair", "chair"}) : "The pine rocking "
               "chair has "
               "a light finish.  It is positioned so that it is "
               "facing the only window.  ",
        ({"possessions", "possession"}) : 
              "The owner's possessions are "
              "in the chests. "
             ]) );
    SetItemAdjectives( ([
                    "chests" : ({"several"}),
                    "bunks" : ({"several"}),
                    "possessions" : ({"owner's"}),                           
                    "table" : ({"small"}) 
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
                       "out" : C_ROOM + "camp1"
                  ]) );
}
