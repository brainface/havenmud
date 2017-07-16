#include <lib.h>
#include "ice.h"
 
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("a trash pile");
SetClimate("arctic");
  SetLong("Smelly rotting objects cover this room in an awful "
          "stench.  Bones of unknown creatures cover the floor.  One very "
          "orcish skeleton has huge teethmarks on it.  One can leave "
          "to the southwest and west into more of the freezing cold.");
  SetItems( ([
               ({ "trash pile","pile","objects","object","garbage" }) :
                  "Disgustingly decomposing, these smelly objects can not "
                  "be identified.",
               ({"room", "ground", "stench", "awful stench"}): (: GetLong :),
               ({ "bones", "bone", "creatures", "creature" }) :
                  "Bleached and white, these bones don't appear to be "
                  "from any specific race.",
               ({ "orcish skeleton", "skeleton","marks","mark",
                  "teethmarks","teethmark", }) :
                  "Half eaten, the skeleton seems to project the "
                  "message, 'This could be you'.",
     ]) );
  SetItemAdjectives( ([
                        "skeleton" : ({ "orcish","orkish","huge",
                                        "half-eaten","teeth" }),
                        "trash pile" : ({ "trash","smelly","rotten",
                                          "rotting" }),
                        "bones" : ({ "bleached","white","unknown" }),
                   ]) );
  SetSmell( ([
               "stench" : "The awful stench would even gag the most "
                          "resilient of people.",
               "default" :
                  "The stench of rotting objects assaults the senses.",
         ]) );
  SetListen( ([
                "default" : "The wind howls loudly, shattered loose ice.",
           ]) );
  SetExits( ([
               "west" : ICE_ROOM + "/yetiroom.c",
               "southwest": ICE_ROOM + "/ropebridge.c",
          ]) );
}


/* Approved by Balishae on Sat Oct  4 23:21:04 1997. */
