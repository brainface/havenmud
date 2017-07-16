//
// Inside the main door
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
room::create();
 SetShort("abandoned guardroom");
 SetLong("This is what once was a heavily protected sentry post, "
         "guarding the only entrance to the underground fortress. It "
         "appears to have been abandoned in a hurry for some reason, "
         "as there is still various bits of rubbish and discarded "
         "armour lying around. To the west, an empty doorframe gives "
         "sad testimony to the decline in this fortress' recent "
         "fortune. To the north, a wide archway leads off further into "
         "the complex.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetExits( ([
              "west" : RNQ_RM + "quarters.c",
              "south" : RNQ_RM + "forect.c",
              "north" : RNQ_RM + "gate1.c",
          ]) );
  SetItems( ([
              ({"discarded armour","rubbish","armour"}) : "The floor is"
                       " covered with old chocolate wrappers and armour"
                       " so rusted as to be completely worthless.",
              ({"doorframe","frame"}) : "The rotting wooden frame"
                       " has no door on it.",
              ({"entrance","archway","wide archway"}) : "The archway is made of "
                       "stone and leads further into the complex.",
              ({"post","guardroom"}) : (:GetLong:),
              ("fortress") :
                "This fortress must have been built a long time ago "
                "to be in such a state, and by someone very powerful"
                " to be this big.",
          ]) );
  SetItemAdjectives( ([
    "post" : ({"sentry","underground"}),
    "fortress" : "underground",
    ]) );
  SetSmell( ([
               "default" : ("The debris gives off a rotting stench"),
               "debris" : ("The stink of the debris is disgusting."),
          ]) );
  SetListen( ([
               "default" : "Strange shuffling can be heard to the west.",
           ]) );
  SetInventory( ([
                  RNQ_NPC + "rat" : 2,
              ]) );
  SetDoor("north", RNQ_OBJ + "door1.c");
}
