/*  Portia  Ruins  10-9-98
    Path through the village.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a dusty walkway");
  SetClimate("tropical");
  SetExits( ([
        "south" : RUINS_ROOMS + "6,-4",
       "east" : RUINS_ROOMS + "7,-3",
          ]) );
  SetSmell( ([
       "default" : "The area smells very earthen.",
          ]) );
  SetListen( ([
       "default" : "The sound of claws on stone can be heard all around.",
          ]) );
  SetInventory( ([
         ]) );
  SetLong("The walkway curves here leading to the south and to the "
          "east. To the north lies three walls that apparently used to be "
          "a building. To the west there is a large pile of stone that "
          "would be impossible to go through. It looks like it may have "
          "been a building at some time.");
  SetItems( ([
        "walkway" : "This dusty walkway leads south to the village and "
                    "east farther into the village.",
        ({"entrance", "village" }) : (:GetLong:),
        ({"foliage", "plants", "vines"}) : "These plants and vines have been here quite some time.",
    ({"pile of stone", "stone", "pile"}) :
          "This pile of stone is the remains of a building that was "
          "destroyed by some sort of attack.",
      ({ "north building", "building", "structure" }) : "Although the "
           "roof and one walls are missing this structure looks as "
           "though it may have some interesting artifacts inside.",
        ]) );
  SetItemAdjectives( ([
        "pile of stone" : ({"large", "east"}),
         "walkway" : "dusty",
         "north building" : "crude",
         ]) );
  SetEnters( ([
           ]) );
  }
/*   [ Portia Approved ] */
