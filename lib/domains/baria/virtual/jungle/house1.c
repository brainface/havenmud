/*   Portia   Ruins  10-9-98
    A house to be entered from 5,-3.c.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a small dwelling");
  SetClimate("tropical");
  SetExits( ([
        "out" : RUINS_ROOMS + "5,-3",
         ]) );
  SetSmell( ([
       "default" : "The area smells earthen.",
       ]) );
  SetListen( ([
      "default" : "The sounds of footsteps can be heard out on the walkway.",
         ]) );
  SetLong("Although there is no ceiling here and only two walls, "
          "one can tell that this used to be a small dwelling. "
          "broken dishes and bits of decaying leather scatter the "
          "floor and there is a skeleton in the corner. Nothing in "
          "here looks very valuable and it seems as if the home had "
          "been raided several times following its destruction.");
  SetItems( ([
     ({"dwelling", "home"}) : (:GetLong:),
     ({"wall", "wall"}) : "Both walls are made of stone and do not "
                         "appear very secure.",
     "dishes" : "What is left of the dishes is scattered about the floor.",
     ({"leather", "bits"}) : "The leather is almost completly decayed "
                             "and completely useless.",
     "floor" : "The floor is full of broken dishes.",
      "skeleton" : "The skeleton is average size and looks too fragile "
                   "to be moved.",
       "dish" : "What is left of the dishes is scattered about the floor.",
             ]) );
  SetItemAdjectives( ([
         "dishes" : "broken",
         "dish" : "broken",
         "dwelling" : "small",
        "leather" : "decaying",
         "skeleton" : "fragile",
           ]) );
  SetInventory( ([
/*
       RUINS_NPC + "rat.c" : 1,
       RUINS_NPC + "spider.c" : 1,
*/
          ]) );
  }
/*   [ Portia Approved ] */
