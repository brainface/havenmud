
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is small and cramped.  "
                 "Trash and dirt are everywhere.  "      
                 "The usual storage chests aren't visible.  "
                 "There is only one bed.  "
                 "Leftover food from previous meals covers"
                 " the table, and even the chairs.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor isn't visible under all the dirt.",
             ("trash"):
                 "Leftover food, old clothing and broken "
                 "toys are among the trash on the floor. ",                   
           ({ "chests", "chest"}):
                "The chests are covered with dirty clothes. ",                
        ({"walls", "dirt", "wall"}) : 
                 "The walls are covered with "
                 "dirt and grime. ",
        ({"table"}) : "The table is so covered with "
               "leftover food that the color cannot be "
               "determined.  ",
        ({"seats", "backs", "chairs", "seat", "back", 
              "chair"}) : 
               "The chair seats are covered with "
               "food, and the backs with clothing. ",
       ("bed") :  "The bed is dirty and unmade.",
       ({"food", "apples", "meat", "vegetables",
           "apple", "vegetable"}): 
               "Rotting apples, maggot covered meat, "
               "and even some fresher meat and vegetables"
               " cover the table and chair seats. ",
        ("clothing") : "The clothing is dirty, old, and "
               "torn.  ",
        ({"toys", "dolls", "blocks", "toy", "doll", 
             "block"}) :
                "Various toys such as dolls and blocks "
                "are left all over the floor.  Many of them"
                " are broken. "       
             ]) );
    SetItemAdjectives( ([
                    "food" : ({"leftover"}),
                    "seats" : ({"chair"}),
                    "backs" : ({"chair"}),
                    "clothing" : ({"old", "dirty"}),
                    "clothes" : ({"dirty", "old"}),
                    "toys" : ({"various", "broken"}),
                    "meat" : ({"maggot covered", 
                          "fresher"}),
                    "apples" : ({"rotting"})
                     ]) );
    SetSmell( ([
                "default" : "The air reeks of dirty diapers."
                          ]) );
    SetListen( ([
                "default" :  "A few noises can be heard  "
                                  "from outside. "
             ]) );
    SetClimate("indoors");
    SetInventory( ([ C_NPC + "baby" : 1]) );
    SetExits( ([
                       "out" : C_ROOM + "camp7"
                  ]) );
}
