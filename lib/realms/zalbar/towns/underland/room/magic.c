/* Underland Mage Circle
   Atrus@Haven
   12/4/2013
 */

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Arcane Academy");
  SetExits( ([
    "out" : UNDER_ROOM "level0hub",
        ]) );
  SetSmell("A large circular room buttressed with large swirling bronze supports "
           "makes up the common room of the mages academy of Underland. "
           "The center of the room is laid out in a circle with a tile mosaic design "
           "as the floor. Runes of power are etched into every surface throughout the "
           "room and pulse in and out of visibility with the flickering fires of large "
           "sconces chained to the ceiling, illuminate the room with an intense purple "
           "light. Cushions and thick blankets are piled around "
           "the base of each of the supports. The walls between the supports are covered "
           "with large hung tapestries depicting great mage battles.  "
           ".");
  SetListen("Stuff that you can hear.");
  SetLong("The long goes here"
    );

  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "hall", "building" }) : "cityhall.",
    ]) );
  SetInventory( ([
    UNDER_NPC "evoker" : 1,
    UNDER_NPC "illusionist" : 1,
    ]) );
}
