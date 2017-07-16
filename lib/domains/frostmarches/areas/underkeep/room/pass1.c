//
// an underground passage
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dank passage");
  SetLong("The passage is long and dank, burrowing through the rock."
    " Water drips from the ceiling with irritating regularity."
    " A small amount of illumination is provided by a greenish glow"
    " from the walls. The walls are of crudely hewn rock, and there is"
    " some kind of writing scrawled on them in red.");
  SetClimate("underground");
  SetAmbientLight(10);
  SetExits( ([
    "north" : RNQ_RM + "pass2.c",
    "south" : RNQ_RM + "gate1.c",
  ]) );
  SetItems( ([
    "passage" : (:GetLong:),
    ({"glow" ,"light"}) :
      "The dim light appears to be coming from some sort of moss "
      "coating the walls.",
    ({"drip" , "water"}) :
      "Water drips down from the stalactites.",
    "ceiling" : "The ceiling is uneven, with stalactites coming down. Curiously,"
      " there are no stalagmites coming up from the floor to meet them.",
    "floor" :
      "The floor seems to be worn smooth by the passage of many feet.",
    ({"stalactites","stalactite"}) :
      "The stalactites are pointy.",
    "moss" :
      "The moss glows softly in the dark.",
    "writing" :
      "There is some some kind of writing on the walls that you could read.",
    ({"crudely hewn rock","rock","wall","walls"}) :
      "The rock is jagged and rough, as it would be if it had"
      " been made by the hands of many slaves wielding crude stone"
      " pickaxes.",
  ]) );
    SetItemAdjectives( ([
      "ceiling" : "dripping",
      "writing" : "red",
      "moss" : "glowing",
      "glow" : ({"greenish","dim"}),
      "rock" : ({"crudely","hewn"}),
      "passage" : ({"long","dank"}),
      ]) );
  SetSmell( ([
    "default" :
      "There is a revolting smell of rotting flesh in here.",
  ]) );
  SetListen ( ([
    "default" :
      "The 'plip-plip' of dripping water is all that can be heard.",
  ]) );
  SetRead( ([
    "writing" :
      "Written in dried blood are the words, 'Beware the stalker!'",
  ]) );
  SetInventory( ([
    RNQ_NPC + "rat" : 3,
  ]) );
}
