
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is small and dark.  "
                 "The entire inside is painted black, even "
                 "the floor and ceiling.  A single table "
                 "draped in a blood red cloth is set up in "
                 "the exact middle of the wagon.  A crystal "
                 "ball and a deck of Tarot cards rest in the "
                 "center of the table.  A single candle "
                 "provides the only source of light.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "table"}) :
                   "The large, round table is covered in a "
                   "blood red table cloth.  ",
             ("cloth"):
                 "The blood red table cloth is made of "
                 "silk and hangs to the floor.",
           ("ball"):
               "The crystal ball is clear and flawless.",
            ({ "cards", "deck", "backs", "card", "back"}):
                "The cards are stacked face-down on the "
                "table.  Their backs are covered in "
                "flowered vines.",  
        ({"walls", "floor", "ceiling", "wall"}) :
                "The walls "
                "floor, and ceiling are pitch black. ",
        ({"candle"}) :  "A large, white candle provides "
                "the only light.  "]) );
    SetItemAdjectives( ([
                    "cards" : ({"Tarot", "tarot"}),
                    "cloth" : ({"table", "red", 
                            "blood red"}),
                    "ball" : ({"crystal"})
                     ]) );
    SetSmell( ([
                "default" : "The air is filled with the scent "
                                  "of wax. "
    
              ]) );
    SetListen( ([
                "default" :  "The room is perfectly silent."
             ]) );
    SetClimate("indoors");
    SetInventory( ([ C_NPC + "fortuneteller" : 1,
               C_NPC + "assistant" : 1]) );
    SetExits( ([
                       "out" : C_ROOM + "camp8"
                  ]) );
}
