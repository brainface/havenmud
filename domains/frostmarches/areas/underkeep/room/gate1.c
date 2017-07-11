//
// The entrance door
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
inherit LIB_ROOM;

static void create() {
room::create();
 SetShort("the end of the passageway");
 SetLong("The crude hewn passageway ends abruptly here, with a "
         "sturdily-built door preventing further progress. The "
         "moss which lines the walls of the passageway has "
         "been scraped off, leaving the walls bare. Stalactites"
         " and stalagmites strain to reach one another, giving "
         "the impression of descending into the maw of some "
         "fabulous monster.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetExits( ([
              "north" : RNQ_RM + "pass1.c",
              "south" : RNQ_RM + "guardhs.c",
          ]) );
  SetItems( ([
              ({"wall","walls"}) : "The walls have been scraped "
                       "clean by the toils of some creature.",
  ({"stalactite","stalactites"}) : "This is a pointy bit of rock "
                       "descending from the ceiling.",
  ({"stalagmite","stalagmites"}) : "This is a pointy bit of rock "
                       "straining upwards from the floor.",
           ({"ceiling","floor"}) : "It has jagged bits of rock"
                       " protruding from it.",
              ("rock") : "These are known as stalactites and "
                       "stalagmites.",
            ({"maw", "monster"}) : "That's just a figure of "
                       "speech. There's no real risk of being "
                       "devoured whole - is there?",
              "passageway" : "The passage extends further to the"
                       " south, while to the north, it ends in a"
                       " door.",
              "moss" : "The moss has been scraped off, possibly by some animal.",
          ]) );
  SetItemAdjectives( ([
    "passageway" : ({"crude","hewn"}),
    "monster" : "fabulous",
    ]) );
  SetSmell( ([
    "default" : "It smells of old bones here.",
          ]) );
  SetListen( ([
               "default" : "The only thing to hear is silence.",
               "door" : "There is an eerie silence.",
           ]) );
  SetInventory( ([
                  RNQ_NPC + "skeleton1" : 1,
              ]) );
  SetDoor("south", RNQ_OBJ + "door1.c");
}
