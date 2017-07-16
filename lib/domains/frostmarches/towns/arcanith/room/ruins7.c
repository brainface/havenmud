/* Remains of the armoury and smithy */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("western ruins");
  SetClimate("temperate");
  
  SetNightLight(15);
  SetExits( ([
     "east"  : ROOM "/ruins6",
  ]) );

  SetLong(
    "The short road leads to a group of three ruined buildings. To the "
    "south are the ruins of a large tavern. A collapsed smithy "
    "to the west has slowly degraded into a pile of rubble. Amazingly, "
    "the armoury to the north has evaded the destruction. "
    "An old sign lies before the rubble to the west. A sign waves "
    "slightly in the breeze above the door of the northern building."
    );

  SetItems( ([
    ({ "short road", "road" })  :
       "The road ends as it leads up to three buildings.",
    ({ "pile of rubble", "rubble" })  :
       "All that remains of the western and southern buildings are piles of "
       "rubble.",
    ({ "smithy", "building", })  :
       "The building to the west has lost its battle with the ages.",
    ({ "armoury", "building", }) :
       "The northern building as withstood the tests of time.  A sign "
       "swings slightly above its door.",
    ({ "tavern", "building", }) :
       "The southern building is in bad shape but still oddly usable.",
    ({ "fallen sign", "sign" })  :
       "The sign depicts an axe and a sword crossed.",
    ({ "swinging sign", "sign" })  :
       "The sign swings slightly in the breeze.  It depicts a breast plate "
       "with a shield behind it.",
  ]) );
  
  SetItemAdjectives( ([
    "tavern" : ({ "south", "southern", "large", }),
    "smithy" : ({ "west", "collapsed", "western", }),
    "armoury": ({ "north", "northern", }),
    ]) );
  
  SetEnters( ([
    "armoury"  : ROOM "/armoury",
    "tavern"   : ROOM "/tavern",
  ]) );

  SetSmell( ([
    "default"  : "The scent of the ages fills this area.",
  ]) );

  SetListen( ([
    "default"  : "The only sound is the creaking of the sign.",
  ]) );

  SetInventory( ([
    NPC "/giant_spider" : 1,
  ]) );
}
