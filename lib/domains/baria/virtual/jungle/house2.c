/*  Portia  Ruins  10-9-98
    A house to be entered from "5,-4.c".
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a ruined dwelling");
  SetClimate("tropical");
  SetExits( ([
       "out" : RUINS_ROOMS + "5,-4",
           ]) );
  SetListen( ([
      "default" : "Footsteps can be heard outside.",
           ]) );
  SetSmell( ([
      "default" : "There is a distinct earthen smell here.",
          ]) );
  SetInventory( ([
/*
        RUINS_NPC + "lizardman1" : 1,
*/
           ]) );
  SetLong("What used to be a nice home is now a set of walls "
          "with no ceiling. Whatever attacked this area was very "
         "powerful and obviously spared no one. There is nothing left "
         "here but a skeleton.");
  SetItems( ([
      ({"dwelling", "home", "set"}) : (:GetLong:),
       ({"walls", "wall"}) : "These walls are all that is left of "
                             "this home.",
       "skeleton" : "The skeleton is very dusty and appears very fragile.",
        ]) );
  SetItemAdjectives( ([
      "dwelling" : ({"nice", "small", "ruined"}),
           ]) );
  }
/*   [ Portia Approved ] */
