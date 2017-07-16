
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("A bed lies against the back wall.  "
         "A few chests are shoved under the bed.  "
         "A table and chairs are set up in the middle "
         "of the room.  On top of the table is a vase "
         "filled with wildflowers.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and has recently been swept. ",
             ({ "vase", "wildflowers", "flowers", "flower",
                   "wildflower"}):
                 "Beautiful wildflowers fill the simple "
                 "glass vase.  ",
         ({ "chests", "chest"}):
                "All of the chests are about the same size "
                "and are painted in bright colors.  There "
                "are no locks on them.  They are used to "
                "store possessions.",
        ({"walls", "wall"}) : "The walls are painted a"
              " sky blue. ",
        ({"table"}) : "The table is simple yet sturdy.  "
                "Vines have been carved into "
                "the legs.   The table top has been left plain "
                "except for the dark varnish.  ",
       ({"vines", "legs", "vine", "leg" }) :
                "Beautiful vines "               
               "are carved into the legs of the "
               "table. ",
        ("chairs") : "The simple, sturdy chairs have the "
               "same varnish as the table.  ",
        ("bed"): "The large four-poster bed has the same"
               " varnish as the table and chairs." 
             ]) );
    SetItemAdjectives( ([
                    "chairs" : ({"chair"}),
                    "chests" : ({"several"}),
                    "wall" : ({"back"})
                    ]) );
    SetSmell( ([
                "default" : "The faint hint of wildflowers "
                                  "wafts through the wagon. "
    
              ]) );
    SetListen( ([
                "default" :  "A lively melody fills the "
                                   "wagon. ",
                "melody" : "The melody is very easy "
                                  "to dance to. "
             ]) );
    SetInventory( ([ C_NPC + "woman" : 1]) );   
    SetClimate("indoors");
    SetExits( ([
                       "out" : C_ROOM + "camp3"
                  ]) );
}
