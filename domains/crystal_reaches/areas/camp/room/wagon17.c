
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is small and incredibly "
                 "clean.  A single bed rests against one "
                 "wall.  A table and chair rests under "
                 "the window.  "
                 "A single large chest sits next to the "
                 "bed.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is light brown and so clean "
                   "it shines.  ",
             ("bed"):
                 "The bed is large, comfortable, and "
                "inviting.  Flowers and vines are carved "
                "into the headboard.",
           ({"headboard", "flowers", "vines", "flower",
               "vine"}) : 
               "Beautiful flowers and vines are "
               "carved into the cherry headboard. ",
          ("window") : "The window lets in lots of light.", 
          ("table"):
               "The table is has been polished until it "
              "shines. ",
            ({ "chair"}):
                "The chair has been polished recently. ",
        ({"walls", "wall"}) : "The walls are sparkling "
              "white. ",
        ({"chest", "animals", "animal"}):
               "The large cedar chest is covered in "
               "carvings of forest animals. ",]) );
 SetItemAdjectives( ([
                    "animals" : ({"forest"}),
                    "chest" : ({"large"}),
                    "bed" : ({"single"}),
                    ]) );
 
   SetSmell( ([
                "default" : "The air is filled with the scent "
                                  "of cedar and polish. "
    
              ]) );
    SetListen( ([
                "default" :  "A few loud noises from "
                                  "outside occasionally pierce "
                                  "the peaceful quiet. "
             ]) );
    SetClimate("indoors");
    SetExits( ([
                       "out" : C_ROOM + "camp9"
                  ]) );
}
