/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: lair01.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: September 10th, 1998
// Abstract: This is the entrance of the lair of Naluris.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor_forest.h"
  static void create()
  {
  room::create();
  SetClimate("temperate");
  SetShort("a dark cave somewhere in the Jidoor Forest");
  SetLong("Just inside the cave, the area becomes damp and filled with "
          "moist air. The tunnel leads west deeper into the bowels of the "
          "cave. The area does not look made by the hands of a humanoid "
          "creature.  In fact, the entire tunnel looks more like a burrow "
          "of a massive creature.");
  SetItems( ([
           ({"ground"}) : "The ground is mostly pebbles and small patches "
              "of plants.",
           ({"plants"}) : "These plants barely grow from the lack of "
              "sunlight.",
           ({"air"}) : "The air? No one can see that.",
           ({"cave"}) : "The cave is dark and musty."
          ]) );
 SetItemAdjectives( ([
            "air" : ({ "musty"}),
            "plants" : ({"small","patches of"})
                  ]) );
  SetListen( ([ 
            "default" : "The cave is strangely quiet."
           ]) );
  SetSmell( ([ 
            "default" : "A musty odor fills the air.",
            "air" : "The air smells musty, with a hint of something else "
              "but you cannot place it."
          ]) );
  SetExits( ([
            "out" : d_room + "/forest02",
            "west" : d_room + "/lair02"
          ]) );
  }
