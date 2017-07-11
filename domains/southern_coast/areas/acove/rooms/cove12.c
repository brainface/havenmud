/*a pirate galleon
 Zara 8/7/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a pirate galleon");

  SetClimate("temperate");


  SetExits( ([
  "east" : ACOVE_ROOMS + "cove9",
    "west" : ACOVE_ROOMS + "cove13",
    ]) );

  SetLong("This part of the ship, near the prow below deck, is empty "
          "except for a neatly coiled rope. The rail is "
          "intact and is well polished. The planks underfoot "
          "are equally well maintained. Although the area "
         "appears deserted, there is an eerie feeling that "
         "it is well guarded.");

  SetItems( ([
       ({"area","part","ship","prow"}) : "This ship is suspiciously "
                             "well maintained for being abandoned.",
       "rope" : "The rope must have belonged to a seaman.",
       ({ "plank","planks" }) : "These planks are made of golden oak.",
     ({ "rail", "rails" }) : "These rails are made of golden oak.",
    ]) );

  SetItemAdjectives( ([
   "coil" : ({"rope","neat"}),
   "rail" : ({"intact","polished"}),
    ]) );
  SetInventory( ([
      ACOVE_NPC + "crew5" : 1,
      ]) );
}
