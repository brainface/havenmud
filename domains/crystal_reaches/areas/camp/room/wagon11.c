
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is the largest in the gypsy "
                 "camp.  "
                 "It obviously belongs to someone of high "
                 "importance in the camp.  A large bed "
                 "fills the back of the wagon.  A dresser and"
                 " wardrobe are next to the bed.  A large "
                 "table and six chairs rest in the middle of "
                 "the room.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and is clean.",
             ("bed"):
                 "The four-poster bed is large with a feather"
                " mattress. It looks very comfortable and "
                "inviting.  The cherry wood has a dark red "
                "finish.  ",
            ("mattress") : "The feather mattress looks "
                "very comfortable. ",
           ("wardrobe"):
               "The wardrobe is made of cedar.  It is tall, "
               "but narrow. ",
            ({ "dresser"}):
                "The dresser is made of cherry and has a "
                "dark red finish.  It is as long as a man is "
                "tall and comes up to shoulder height.  ",  
        ({"walls", "wall"}) : "The walls are dark blue. ",
        ({"table"}) : "The table is simple yet elegant.  "
              "It is made of cherry and finished in dark "
              "red.  ",
        ({"chairs", "chair"}) :
               "The chairs are simple and elegant.  "
               "They are finished to match the table. ",]) );
    SetItemAdjectives( ([
                    "chests" : ({"several"}),
                    "hammocks" : ({"three"}),
                    "mattress" : ({"feather"}),
                    "bed" : ({"large"})
                    ]) );
    SetSmell( ([
                "default" : "The air is filled with the scent "
                                  "of cedar. "
    
              ]) );
    SetListen( ([
                "default" :  "A few loud noises from "
                                  "outside occasionally pierce "
                                  "the peaceful quiet. "
             ]) );
    SetClimate("indoors");
    SetInventory( ([ C_NPC + "leader" : 1]) );
    SetExits( ([
                       "out" : C_ROOM+ "camp5"
                  ]) );
}
