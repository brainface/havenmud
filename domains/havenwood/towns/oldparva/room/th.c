#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetClimate("indoors");
   SetDomain("HavenWood");
   SetAmbientLight(35);
   SetShort("inside the Town Hall");
   SetLong("The town hall exists for town meeting; all the citizens "
           "may come and air their opinions in front of their "
           "peers.  There are rows of benches and a raised area "
           "for the speaker.  An opening in the shack leads out "
           "to the rest of the town; a staircase in the back "
           "leads up to the post office.");
   SetItems( ([
                ({ "Town Hall","hall","town","shack","building" }) :
                   (: GetLong :),
                ({ "bench rows","benches","bench","rows","row" }) :
                   "The wooden benches are nothing special; "
                   "it would be very easy to accidently get a "
                   "splinter while sitting on them or brushing "
                   "up near them.  They are rough and unworn.",
                ({ "town hall podium","raised area","area",
                   "podium" }) : 
                   "The podium is a raised area up at the front "
                   "of the shack; the benches are all aligned "
                   "parellel to it.  It is simply a place for "
                   "the speakers to stand so that all assembled "
                   "may view them.",
                ({ "back staircase","staircase","stairs","stair" }) :
                   "The staircase in the back of the room is "
                   "for the post office; it leads to the second "
                   "floor of the building.",
           ]) );
   SetItemAdjectives( ([
                         "benches" : ({ "rows of","row of",
                                        "bench","wood","wooden" }),
                         "hall" : ({ "town" }),
                    ]) );
   SetListen( ([
                 "default" : "The scuffling noises of the town come "
                    "from outside.",
            ]) );
   SetSmell( ([
                "default" : "The town hall smells of sweat and "
                   "the residue of many people squished into one "
                   "small room.",
           ]) );
   SetExits( ([
                "out" : P_ROOM + "/path1",
                "up"  : P_ROOM + "/po",
           ]) );
   SetInventory( ([
               P_NPC + "/mayor" : 1,
//             P_OBJ + "/town_board" : 1,
              ]) );
   SetNewsgroups( ({ "town.parva" }) );
}
