// an underground passage
// by Ranquest@Haven
//
// This is the starting room, which needs to be linked to the Frostmarches or something
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dank passage");
  SetLong(
    "Here, the rocky scree ends in a corridor. It looks like this corridor"
    " once led from north to south, but the roof has collapsed, opening up"
    " a new entrance and inadvertantly closing off one of the original paths"
    " to the north. The scree has totally blocked off all passage to the"
    " north.");
  SetClimate("underground");
  SetAmbientLight(10);
  SetExits( ([
    "south" : RNQ_RM + "pass1.c",
    ]) );
  SetItems( ([
    "scree" : "The scree is a loosely packed collection of small rocks and"
      " a few larger boulders.",
    ({"small rocks","rocks"}) : "The rocks are jagged and dusty.",
    ({"roof","sky"}) : "A hint of blue sky can be seen far overhead.",
    "entrance" : "The way in--and out--is up over the scree.",
    ({"south path","path"}) :
      "The corridor extends further to the south.",
    ({"north path","path"}):
      "The corridor is blocked to the north by the scree.",
    "corridor" : "The corridor is made of crudely hewn rock.",
    ({"crudely hewn rock","rock"}) :
      "The rock is jagged and rough, as it would be if it had"
      " been made by the hands of many slaves wielding crude stone"
      " pickaxes.",
    ]) );
  SetItemAdjectives( ([
    "scree" : "rocky",
    "roof" : "collapsed",
    "entrance" : ({"new","original"})
    ]) );
  SetSmell( ([
    "default" :
      "There is a revolting smell of rotting flesh in here, as if some "
      "creature had crawled in and died recently.",
  ]) );
  SetListen ( ([
    "default" :
      "There is an eerie silence.",
  ]) );
  SetInventory( ([
    RNQ_NPC + "rat" : 1,
    RNQ_OBJ + "scree" : 1,
  ]) );
}
