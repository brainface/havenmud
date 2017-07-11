
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is large.  "
                 "It obviously belongs to someone of high "
                 "importance in the camp.  A large bed "
                 "rests in one corner.  A large chest "
                 "is next to the bed.  A small table and a "
                 "chair are in another corner.  Near the "
                 "window "
                 "is a music stand with music. ");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and is clean.",
             ("bed"):
                 "The bed is large.  It looks very "
                "comfortable and "
                "inviting.  The pine has a light brown "
                "finish.  ",
           ({"music stand", "stand"}):
               "The music stand is made of beautifully "
               "carved pine.",
            ("music"): 
               "The sheet music is still very rudimentary. "
               " Specific notes are not able to be "
               "determined.  The markings indicate how "
               "long the note should be held and whether "
               "it is higher or lower in pitch.  Only a "
               "talented musician could accurately play "
               "the piece. ",
        ({"window"}) : "The window lets in plenty of "
               "light by which to read the music. ",    
        ({ "chest"}):
                "The chest is made of pine and has a "
                "light brown finish.  It is twice the size "
                "of the chests other gypsies use.  ",  
        ({"walls", "wall"}) : "The walls are dark blue. ",
        ({"table"}) : "The table is simple yet elegant.  "
              "It is made of pine and finished in light "
              "brown.  ",
        ({"chairs", "chair"}) :
               "The chairs are simple and elegant.  "
               "They are finished to match the table. ",]) );
    SetItemAdjectives( ([
                    "bed" : ({"large"}),
                    "music" : ({"sheet"})
                    ]) );
    SetSmell( ([
                "default" : "The air is filled with the scent "
                                  "of pine. "
    
              ]) );
    SetListen( ([
                "default" :  "A few loud noises from "
                                  "outside occasionally pierce "
                                  "the peaceful quiet. "
             ]) );
    SetClimate("indoors");
    SetInventory( ([ C_NPC + "musician" : 1]) );
    SetExits( ([
                       "out" : C_ROOM + "camp6"
                  ]) );
}
