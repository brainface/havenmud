/* dining hall
  Zara 8/6/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
 room::create();
 SetShort("dining hall");
 SetClimate("temperate");
  SetAmbientLight(50);
 SetExits( ([
        "west" : ACOVE_ROOMS + "cove10",
         "down" : ACOVE_ROOMS + "cove14",
       "up" : ACOVE_ROOMS + "cove6",
         ]) );
 SetLong("The ship's dining hall is recognizable by the "
        "long trestle tables bolted to the floor. "
       "The tables are scarred and darkened with age. "
        "Dust motes dance in the faint light that penetrates "
       "the small port hole. A lone tin cup rests on its "
        "side on the table.");
 SetItems( ([
        "ship" : "This deserted pirate ship exudes evil.",
        "hall" : "This room is likely where the pirates gathered to eat.",
       ({ "table", "tables" }) : "These tables are old and scarred.",
        ({ "mote", "motes" }) : "Small particles of dust seem to be "
                                "suspended in air. ",
        ({"porthole","portholes","port hole","hole","glass"}) :
                                        "The glass in these portholes "
                                        "is cracked and dirty. ",
       "cup" : "This tin cup was used for drinking. It "
               "is bent and dented. ",
       ({"floor","plank","planks"}) : "The old oak planks that "
                                     "make up the floor have been worn "
                                       "smooth over time.",
       ]) );
 SetItemAdjectives( ([
  "tables" : ({"trestle","long","scarred","darkened"}),
  "light" : ({ "faint" }),
  "cup" : ({"lone","bent","dented","tin"}),
  ]) );
  SetInventory( ([
       ACOVE_NPC + "crew2" : 1
       ]) );
}
