
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is small and comfortable.  "
                 "A single small bed is pushed up against "
                 "the back wall.  A long table rests under "
                 "the window.  Paints, paintbrushes and "
                 "unfinished Tarot cards litter the tabletop. "
                 "A single large chest sits next to the "
                 "table.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is light brown and clean.  ",
             ("bed"):
                 "The bed is large with a feather"
                " mattress. It looks very comfortable and "
                "inviting.  ",
           ("table"):
               "The long table is cluttered with all the "
               "paint, paintbrushes, and Tarot cards. ",
            ({ "cards", "The Hanged Man", "Man", 
                 "card"}):
                "The cards are look like beautiful yet "
                "haunting pictures.  It appears that the "
                "artist is working on the Major Arcana.  "
                "The Fool, The Lovers, and The Moon are "
                "finished.  The Hanged Man is in a cleared"
                " area.  Only the gallows have been painted"
                " on The Hanged Man's card.", 
        ({"The Fool", "Fool"}) : "This card has a picture"
                " of a man with a few birds. ",
        ({"The Moon", "Moon"}) : "This card depicts "
               "an owl flying below a large full moon. ",
       ({"The Lovers", "Lovers"}) : "This card depicts "
                " a man and woman embracing. ",
        ({"walls", "wall"}) : "The walls are royal blue. ",
        ({"paint"}) :  "Paints in all shades are spread "
               "on the table.  ",
        ({"paintbrushes", "paintbrush"}) :
               "Small delicate paintbrushes "
                "rest randomly about the table.  One with "
               "gray paint lies next to The Hanged Man's "
               "card. ",
         ({"images", "stars", "image", "star"}):
              "Images of the stars "
              "are on the chest. "
           ]) );
    SetItemAdjectives( ([
                    "cards" : ({"Tarot", "tarot", 
                            "unfinished"}),
                    "bed" : ({"single", "small"}),
                    "wall" : ({"back"}),
                    "table" : ({"long"}),
                    "paint" : ({"gray"}),
                    "Man" : ({"Hanged"})
                     ]) );
    SetSmell( ([
                "default" : "The air is filled with the scent "
                                  "of cedar and paints. "
    
              ]) );
    SetListen( ([
                "default" :  "A few loud noises from "
                                  "outside occasionally pierce "
                                  "the peaceful quiet. "
             ]) );
    SetClimate("indoors");
  SetInventory( ([
     C_OBJ + "chestw15" : 1,
  ]) );
    SetExits( ([
                       "out" : C_ROOM + "camp8"
                  ]) );
}
